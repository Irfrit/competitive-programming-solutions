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
  string s;
  cin >> s;
  sort(all(s));

  if (s[0] != s[k - 1]) {
    cout << s[k - 1] << "\n";
  } else if (s[k] != s[n - 1]) {
    cout << s[0] << s.substr(k) << "\n";
  } else {
    cout << s[0];
    for (int i = 0; i < (n - 1) / k; i++) {
      cout << s[n - 1];
    }
    cout << "\n";
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
