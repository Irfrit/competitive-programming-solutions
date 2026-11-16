#include <bit>
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
  int n, k;
  cin >> n >> k;

  string a;
  cin >> a;

  int u = count(all(a), '0');
  int o = count(all(a), '1');

  int z = min({u, o, k});

  int i = max(u, o) + z;
  int l = min(u, o) - z;

  ll ans = 1LL + 1LL * i * (i + 1) / 2 + 1LL * l * (l + 1) / 2;

  cout << ans << '\n';
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
