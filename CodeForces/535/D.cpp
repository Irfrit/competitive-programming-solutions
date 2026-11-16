#include <bits/stdc++.h>
#include <string_view>

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

vector<int> z_function(string_view s) {
  int n = sz(s);
  int l = 0, r = 0;
  vector<int> z(n, 0);

  for (int i = 1; i < n; i++) {
    if (i < r) {
      z[i] = min(r - i, z[i - l]);
    }
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      z[i]++;
    }
    if (i + z[i] > r) {
      l = i;
      r = i + z[i];
    }
  }
  return z;
}

ll binpow(ll a, ll b, ll mod) {
  int result = 1;

  while (b > 0) {
    if (b & 1)
      result = result * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return result;
}

constexpr ll MOD = 10e8 + 7LL;

void solve() {
  int n, m;
  cin >> n >> m;
  string p;
  cin >> p;
  auto z = z_function(p);
  vector<int> pos(m);
  for (auto &x : pos)
    cin >> x;

  bool valid = true;
  int tosub = 0;
  for (int i = 0; i < m; i++) {
    if (i == 0) {
      tosub += sz(p);
      continue;
    }
    int delta = pos[i] - pos[i - 1];
    if (z[delta] < sz(p) - delta) {
      valid = false;
      break;
      ;
    }
    tosub += min(delta, sz(p));
  }

  if (!valid) {
    cout << 0 << "\n";
  } else {
    cout << binpow(26, n - tosub, MOD) << "\n";
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
