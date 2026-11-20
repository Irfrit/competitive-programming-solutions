#include <bits/stdc++.h>
#include <deque>

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
  int Q;
  cin >> s >> Q;
  deque<char> dq;
  for (char c : s)
    dq.push_back(c);
  bool reversed = false;

  while (Q--) {
    int x;
    cin >> x;
    if (x == 1) {
      reversed = (reversed) ? 0 : 1;
    } else {
      int F;
      char C;
      cin >> F >> C;
      if (F == 1) {
        ((reversed == 0) ? dq.push_front(C) : dq.push_back(C));
      } else {
        ((reversed == 0) ? dq.push_back(C) : dq.push_front(C));
      }
    }
  }
  if (reversed) {
    for (auto it = dq.rbegin(); it != dq.rend(); ++it)
      cout << *it;
  } else {
    for (char c : dq)
      cout << c;
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
