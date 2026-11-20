#include <bits/stdc++.h>
#include <map>
#include <stack>

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
  map<char, char> a = {{']', '['}, {')', '('}, {'>', '<'}};
  stack<char> st;
  string s;
  cin >> s;
  for (auto ch : s) {
    if (a.contains(ch)) {
      if (st.empty() || a[ch] != st.top()) {
        cout << "No" << "\n";
        return;
      }
      st.pop();
    } else {
      st.push(ch);
    }
  }
  if (st.empty())
    cout << "Yes" << "\n";
  else
    cout << "No" << "\n";
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
