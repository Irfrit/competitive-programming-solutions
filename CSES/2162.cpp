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
  cin >> N;
  bool toggle = 1;
  queue<int> q;
  for (int i = 1; i <= N; i++) {
    q.push(i);
  }
  while (!q.empty()) {
    if (toggle) {
      auto temp = q.front();
      q.pop();
      q.push(temp);
      toggle = 0;
    } else {
      auto temp = q.front();
      q.pop();
      cout << temp << " ";
      toggle = 1;
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
