#pragma once

#include <vector>
#include <algorithm>

// Lowest Common Ancestor (LCA) using Binary Lifting
struct LCA {
  int n, max_log;
  std::vector<std::vector<int>> adj;
  std::vector<std::vector<int>> up;
  std::vector<int> depth;

  explicit LCA(int n_ = 0) : n(n_), max_log(32 - __builtin_clz(std::max(1, n_))), adj(n_), up(n_, std::vector<int>(max_log, 0)), depth(n_, 0) {}

  void add_edge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  void build(int root = 0) {
    auto dfs = [&](auto& self, int u, int p, int d) -> void {
      up[u][0] = p;
      depth[u] = d;
      for (int i = 1; i < max_log; i++) {
        up[u][i] = up[up[u][i - 1]][i - 1];
      }
      for (int v : adj[u]) {
        if (v != p) self(self, v, u, d + 1);
      }
    };
    dfs(dfs, root, root, 0);
  }

  int get_lca(int u, int v) const {
    if (depth[u] < depth[v]) std::swap(u, v);
    for (int i = max_log - 1; i >= 0; i--) {
      if (depth[u] - (1 << i) >= depth[v]) {
        u = up[u][i];
      }
    }
    if (u == v) return u;
    for (int i = max_log - 1; i >= 0; i--) {
      if (up[u][i] != up[v][i]) {
        u = up[u][i];
        v = up[v][i];
      }
    }
    return up[u][0];
  }

  int get_dist(int u, int v) const {
    return depth[u] + depth[v] - 2 * depth[get_lca(u, v)];
  }
};
