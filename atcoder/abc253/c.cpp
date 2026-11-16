#include <bits/stdc++.h>
#include <set>

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
  map<int, int> a;
  int Q;
  cin >> Q;
  while (Q--) {
    int command;
    cin >> command;
    int x, c;
    switch (command) {
    case 1:
      cin >> x;
      a[x]++;
      break;
    case 2: {
      cin >> x >> c;
      auto it = a.find(x);
      if (it != a.end()) {
        it->second -= min(c, it->second);
        if (it->second == 0) {
          a.erase(x);
        }
      }
      break;
    }
    case 3:
      cout << a.rbegin()->first - a.begin()->first << "\n";
      break;
    }
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
