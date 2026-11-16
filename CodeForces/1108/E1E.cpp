#include <bits/stdc++.h>
#include <cstdlib>
#include <iostream>

using namespace std;

using ll = long long;
using ar = array<int, 2>;
using db = double;

#define all(x) (x).begin(), (x).end()
#define sz(x) static_cast<int>((x).size())

template <typename T> bool ckmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return true;
  }
  return false;
}

template <typename T> bool ckmax(T &a, const T &b) {
  if (b > a) {
    a = b;
    return true;
  }
  return false;
}

void solve() {
  int n, m;
  cin >> n >> m;

  vector<int> values(n);
  vector<pair<int, int>> segments(m);

  for (auto &x : values)
    cin >> x;
  for (auto &[l, r] : segments)
    cin >> l >> r;

  int best_result = 0;
  vector<int> best_segments;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      vector<int> lsegments;
      for (int segment = 0; segment < m; segment++) {
        int l = segments[segment].first - 1, r = segments[segment].second - 1;
        bool contains_i = (l <= i && i <= r);
        bool contains_j = (l <= j && j <= r);

        if (contains_j && !contains_i) {
          lsegments.push_back(segment);
        }
      }
      int result = values[i] - values[j] + (int)lsegments.size();
      if (result > best_result) {
        best_result = result;
        best_segments = lsegments;
      }
    }
  }
  cout << best_result << "\n" << best_segments.size() << "\n";
  for (int k : best_segments)
    cout << k + 1 << " ";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  // cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
