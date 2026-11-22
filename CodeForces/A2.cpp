#include <bits/stdc++.h>
#include <ostream>

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
  string res = "+";
  for (int i = 0; i < n + 2; i++)
    res += "--+";
  cout << res << '\n';
  cout.flush();

  int k;
  cin >> k;

  int i = (k == 0 ? 0 : (k + 2) / 3);
  cout << n + i << '\n';
  cout.flush();
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
