#include <bits/stdc++.h>
#include <deque>

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
  deque<pair<ll, ll>> q;
  int Q;
  cin >> Q;
  while (Q--) {
    int n;
    cin >> n;
    switch (n) {
    case 1:
      int c, x;
      cin >> c >> x;
      q.emplace_back(x, c);
      break;
    case 2:
      ll k, res = 0;
      cin >> k;
      while (k > 0) {
        auto [x, c] = q.front();
        ll take = min(k, c);
        res += take * x;
        k -= take;
        q.front().second -= take;
        if (q.front().second == 0) {
          q.pop_front();
        }
      }
      cout << res << "\n";
      break;
    }
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
