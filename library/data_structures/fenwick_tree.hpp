#pragma once

#include <vector>

// 1-indexed Fenwick Tree (Binary Indexed Tree) for point update and prefix sum query
template <typename T = long long>
struct FenwickTree {
  int n;
  std::vector<T> tree;

  explicit FenwickTree(int n_ = 0) : n(n_), tree(n_ + 1, 0) {}

  // Add val to position i (1-indexed)
  void add(int i, T val) {
    for (; i <= n; i += i & -i) {
      tree[i] += val;
    }
  }

  // Prefix sum [1, i] (1-indexed)
  T query(int i) const {
    T sum = 0;
    for (; i > 0; i -= i & -i) {
      sum += tree[i];
    }
    return sum;
  }

  // Range sum [l, r] (1-indexed)
  T query(int l, int r) const {
    if (l > r) return 0;
    return query(r) - query(l - 1);
  }
};
