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
  string s;
  cin >> s;
  sort(all(s));
  vector<string> result;
  do {
    result.push_back((s));
  } while (next_permutation(all(s)));

  cout << sz(result) << "\n";
  for (auto &x : result) {
    cout << x << "\n";
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
