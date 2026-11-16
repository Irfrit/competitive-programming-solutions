#include <bits/stdc++.h>
#include <cstddef>

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
  int H, W, N;
  cin >> H >> W >> N;
  string T;
  cin >> T;
  int result = 0;
  vector<string> a(H);
  vector<pair<int, int>> points{};
  for (int i = 0; i < H; i++) {
    cin >> a[i];
    for (int j = 0; j < W; j++) {
      if (a[i][j] == '.')
        points.push_back({i, j});
    }
  }
  for (auto point : points) {
    bool valid = 1;
    for (int i = 0; i < N; i++) {
      if (T[i] == 'L')
        point.second--;
      else if (T[i] == 'R')
        point.second++;
      else if (T[i] == 'U')
        point.first--;
      else if (T[i] == 'D')
        point.first++;
      if (a[point.first][point.second] == '#') {
        valid = 0;
        break;
      }
    }
    if (valid) {
      result++;
    }
  }
  cout << result;
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
