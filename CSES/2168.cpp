#include <algorithm>
#include <bits/stdc++.h>
#include <climits>

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
  int n;
  cin >> n;
  vector<vector<int>> ranges;
  vector<bool> contains(n), contained(n);
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    ranges.push_back({a, b, i});
  }
  sort(all(ranges), [](const auto &a, const auto &b) {
    if (a[0] != b[0])
      return a[0] < b[0];
    return a[1] > b[1];
  });
  int maxRight = 0;
  for (int i = 0; i < n; i++) {
    if (ranges[i][1] <= maxRight) {
      contained[ranges[i][2]] = true;
    }
    maxRight = max(maxRight, ranges[i][1]);
  }

  int minRight = INT_MAX;
  for (int i = n - 1; i >= 0; i--) {
    if (ranges[i][1] >= minRight) {
      contains[ranges[i][2]] = true;
    }
    minRight = min(minRight, ranges[i][1]);
  }

  for (auto x : contains)
    cout << x << " ";
  cout << "\n";
  for (auto x : contained)
    cout << x << " ";
  cout << "\n";
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
