#include <bits/stdc++.h>
#include <climits>

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
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  int ans = INT_MAX;

  for (int i = 0; i <= 2 * max(X, Y); i++) {
    int cost = i * C;

    cost += max(0, (2 * X - i + 1) / 2) * A;

    cost += max(0, (2 * Y - i + 1) / 2) * B;

    ans = min(cost, ans);
  }

  cout << ans << "\n";
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
