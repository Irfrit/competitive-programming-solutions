#include <bits/stdc++.h>
#include <cstdlib>

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
  int N;
  cin >> N;
  vector<array<int, 3>> a(N);
  for (auto &[x, y, h] : a)
    cin >> x >> y >> h;
  for (int i = 0; i <= 100; i++) {
    bool found = false;
    for (int j = 0; j <= 100; j++) {
      int H = 0;
      for (auto [x, y, h] : a) {
        if (h > 0) {
          H = h + abs(x - i) + abs(y - j);
          break;
        }
      }
      bool valid = true;
      for (auto [x, y, h] : a) {
        int cand = max(H - abs(x - i) - abs(y - j), 0);
        if (cand != h) {
          valid = false;
          break;
        }
      }
      if (valid) {
        cout << i << ' ' << j << ' ' << H << '\n';
        found = true;
        break;
      }
    }
    if (found)
      break;
  }
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
