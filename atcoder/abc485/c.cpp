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
  vector<int> a(N);
  for (auto &x : a)
    cin >> x;

  vector<int> result(N);
  int l = 0;

  while (l < N) {
    int r = l;
    while (r + 1 < N && a[r + 1] == a[l]) {
      r++;
    }
    for (int j = l; j <= r; j++) {
      int dist = N;
      if (l > 0)
        ckmin(dist, j - l + 1);
      if (r + 1 < N)
        ckmin(dist, r + 1 - j);
      result[j] = dist;
    }
    l = r + 1;
  }

  for (int i = 0; i < N; i++) {
    cout << result[i] << " ";
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
