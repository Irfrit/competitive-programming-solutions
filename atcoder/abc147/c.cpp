#include <bits/stdc++.h>

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
  int result = 0;
  int N;
  cin >> N;
  vector<vector<pair<int, int>>> a(N);
  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;
    for (int j = 0; j < A; j++) {
      int x, y;
      cin >> x >> y;
      a[i].push_back({x, y});
    }
  }

  for (int b = 0; b < (1 << N); b++) {
    bool valid = true;
    vector<int> subset;
    for (int i = 0; i < N; i++) {
      if (b & (1 << i))
        subset.push_back(i);
    }
    for (auto c : subset) {
      for (auto [x, y] : a[c]) {
        if (((b >> (x - 1)) & 1) != y)
          valid = false;
      }
    }
    if (valid)
      result = max(result, popcount(static_cast<unsigned>(b)));
  }
  cout << result << "\n";
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
