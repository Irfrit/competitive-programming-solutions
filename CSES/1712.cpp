#include <bits/stdc++.h>
#include <cmath>
#include <regex>

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

constexpr ll MOD = 1e9 + 7;

ll mod_pow(ll base, ll exponent, ll mod) {
  ll result = 1;
  base %= mod;
  while (exponent > 0) {
    if (exponent & 1) {
      result = result * base % mod;
    }
    base = base * base % mod;
    exponent >>= 1;
  }
  return result;
}

void solve() {
  ll a, b, c;
  cin >> a >> b >> c;
  if (a == 0) {
    cout << (b == 0 && c > 0 ? 1 : 0) << "\n";

  } else {
    ll exponent = mod_pow(b, c, MOD - 1);
    cout << mod_pow(a, exponent, MOD) << "\n";
  }
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
