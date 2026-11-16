#include <bits/stdc++.h>
#include <cstdint>

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
  vector<ll> weights(n);
  for (ll &w : weights)
    cin >> w;

  ll ans = INT64_MAX;

  for (int mask = 0; mask < 1 << n; mask++) {
    ll sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++) {
      if (mask & (1 << i)) {
        sum1 += weights[i];
      } else {
        sum2 += weights[i];
      }
    }
    ans = min(ans, abs(sum1 - sum2));
  }

  cout << ans << "\n";
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
