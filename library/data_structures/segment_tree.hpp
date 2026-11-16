#pragma once

#include <vector>
#include <functional>

// Iterative Segment Tree (0-indexed, half-open intervals [l, r))
template <typename T>
struct SegmentTree {
  int n;
  std::vector<T> tree;
  T id;
  std::function<T(const T&, const T&)> combine;

  SegmentTree(int n_, T id_, std::function<T(const T&, const T&)> combine_)
      : n(n_), id(id_), combine(combine_) {
    tree.assign(2 * n, id);
  }

  void build(const std::vector<T>& a) {
    n = a.size();
    tree.assign(2 * n, id);
    for (int i = 0; i < n; i++) tree[n + i] = a[i];
    for (int i = n - 1; i > 0; --i) tree[i] = combine(tree[i << 1], tree[i << 1 | 1]);
  }

  // Point update: set a[p] = val
  void set(int p, T val) {
    for (tree[p += n] = val; p > 1; p >>= 1) {
      tree[p >> 1] = combine(tree[p & ~1], tree[p | 1]);
    }
  }

  // Point update: a[p] = combine(a[p], val)
  void apply(int p, T val) {
    p += n;
    tree[p] = combine(tree[p], val);
    for (; p > 1; p >>= 1) {
      tree[p >> 1] = combine(tree[p & ~1], tree[p | 1]);
    }
  }

  // Range query over [l, r) (0-indexed)
  T query(int l, int r) const {
    T res_l = id, res_r = id;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) res_l = combine(res_l, tree[l++]);
      if (r & 1) res_r = combine(tree[--r], res_r);
    }
    return combine(res_l, res_r);
  }
};
