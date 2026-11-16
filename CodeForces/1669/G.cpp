#include <bits/stdc++.h>
#include <cstdint>

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
  int n, m;
  cin >> n >> m;
  vector<string> a(n);

  for (auto &row : a)
    cin >> row;

  for (int col = 0; col < m; col++) {
    int row = n - 1;
    while (row > 0) {
      if (a[row][col] == '.' && a[row - 1][col] == '*') {
        swap(a[row][col], a[row - 1][col]);
        row = n - 1;
      } else {
        row--;
      }
    }
  }
  for (auto row : a) {
    cout << row << "\n";
  }
  cout << "\n";
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
