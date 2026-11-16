#include <bits/stdc++.h>
#include <csignal>

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
  vector<string> v;
  while (n--) {
    string s;
    cin >> s;
    v.push_back(s);
  }
  sort(all(v), [](const auto &a, const auto &b) { return a + b < b + a; });

  for (auto x : v) {
    cout << x;
  }
  cout << "\n";
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
