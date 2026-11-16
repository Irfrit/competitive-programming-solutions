#include <algorithm>
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
  int N;
  string S;
  cin >> N >> S;

  int ans = 0;

  for (int num = 0; num < 1000; num++) {
    string pin = to_string(num);

    while (sz(pin) < 3) {
      pin = "0" + pin;
    }
    int idx = 0;

    for (char c : S) {
      if (c == pin[idx]) {
        idx++;
      }
      if (idx == 3) {
        ans++;
        break;
      }
    }
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
