#pragma once

#include <vector>
#include <numeric>

// Disjoint Set Union (DSU / Union-Find) with path compression and size tracking
struct DSU {
  int n, comps;
  std::vector<int> parent, sz;

  explicit DSU(int n_ = 0) : n(n_), comps(n_), parent(n_), sz(n_, 1) {
    std::iota(parent.begin(), parent.end(), 0);
  }

  int find(int x) {
    return parent[x] == x ? x : parent[x] = find(parent[x]);
  }

  bool same(int x, int y) {
    return find(x) == find(y);
  }

  bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (sz[x] < sz[y]) std::swap(x, y);
    parent[y] = x;
    sz[x] += sz[y];
    comps--;
    return true;
  }

  int size(int x) {
    return sz[find(x)];
  }

  int count_components() const {
    return comps;
  }
};
