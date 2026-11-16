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

constexpr ll MOD = 1'000'000'007LL;
ll power(ll b, ll e) {
  b %= MOD;
  ll r = 1;
  while (e > 0) {
    if (e & 1)
      r = r * b % MOD;
    b = b * b % MOD;
    e >>= 1;
  }
  return r;
}
void solve() {
  int n;
  cin >> n;
  vector<ll> c(n);
  for (auto &x : c)
    cin >> x;
  sort(c.begin(), c.end(), greater<>());
  c.push_back(0);

  ll result = 1;
  for (int k = 1; k <= n; k++) {
    if (c[k - 1] <= c[k])
      break;
    result = (result + power(c[k - 1] - 1, k)) % MOD;
  }
  cout << result << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
