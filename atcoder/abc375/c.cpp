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
  vector<string> a(N);
  vector<string> c(N, string(N, ' '));

  for (auto &row : a)
    cin >> row;

  for (int row = 0; row < N; row++) {
    for (int col = 0; col < N; col++) {
      int level = min({row, col, N - row - 1, N - col - 1});
      int rots = (level + 1) % 4;
      int new_row = 0, new_col = 0;
      switch (rots) {
      case 0:
        new_row = row;
        new_col = col;
        break;
      case 1:
        new_row = col;
        new_col = N - row - 1;
        break;
      case 2:
        new_row = N - 1 - row;
        new_col = N - 1 - col;
        break;
      case 3:
        new_row = N - col - 1;
        new_col = row;
        break;
      }
      c[new_row][new_col] = a[row][col];
    }
  }
  for (auto &row : c) {
    cout << row << "\n";
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
