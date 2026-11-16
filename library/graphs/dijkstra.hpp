#pragma once

#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

template <typename T = long long>
struct Dijkstra {
  struct Edge {
    int to;
    T cost;
  };

  int n;
  std::vector<std::vector<Edge>> adj;
  std::vector<T> dist;
  std::vector<int> parent;
  static constexpr T INF = std::numeric_limits<T>::max() / 2;

  explicit Dijkstra(int n_ = 0) : n(n_), adj(n_), dist(n_, INF), parent(n_, -1) {}

  void add_edge(int u, int v, T w, bool directed = false) {
    adj[u].push_back({v, w});
    if (!directed) adj[v].push_back({u, w});
  }

  void run(int start_node) {
    dist.assign(n, INF);
    parent.assign(n, -1);
    using State = std::pair<T, int>;
    std::priority_queue<State, std::vector<State>, std::greater<State>> pq;

    dist[start_node] = 0;
    pq.push({0, start_node});

    while (!pq.empty()) {
      auto [d, u] = pq.top();
      pq.pop();

      if (d > dist[u]) continue;

      for (const auto& [v, cost] : adj[u]) {
        if (dist[u] + cost < dist[v]) {
          dist[v] = dist[u] + cost;
          parent[v] = u;
          pq.push({dist[v], v});
        }
      }
    }
  }

  std::vector<int> get_path(int target) const {
    if (dist[target] == INF) return {};
    std::vector<int> path;
    for (int curr = target; curr != -1; curr = parent[curr]) {
      path.push_back(curr);
    }
    std::reverse(path.begin(), path.end());
    return path;
  }
};
