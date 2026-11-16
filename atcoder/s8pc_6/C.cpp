#include <bits/stdc++.h>
#include <vector>

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

  vector<ll> a, b;
  ll res = 0;
  for (int i = 0; i < n; ++i) {
    ll A, B;
    cin >> A >> B;
    a.push_back(A);
    b.push_back(B);
    res += B - A;
  }
  sort(all(a));
  sort(all(b));

  ll median_a = a[n / 2];
  ll median_b = b[n / 2];

  for (ll x : a)
    res += llabs(x - median_a);
  for (ll x : b)
    res += llabs(x - median_b);

  cout << res << "\n";
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
