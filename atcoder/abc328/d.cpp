#include <bits/stdc++.h>
#include <stack>
#include <string>

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
  string S;
  cin >> S;
  string st;
  st.reserve(S.size());

  for (char c : S) {
    st.push_back(c);
    auto n = sz(st);
    if (n >= 3 && st[n - 3] == 'A' && st[n - 2] == 'B' && st[n - 1] == 'C') {
      st.erase(n - 3);
    }
  }

  cout << st << "\n";
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
