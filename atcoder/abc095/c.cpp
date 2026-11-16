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
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  int cc = 0;
  if (2 * C < A + B) {
    cc = 2 * min(X, Y);
    X -= cc / 2;
    Y -= cc / 2;
  }

  if (X > 0 && 2 * C < A) {
    cc += 2 * X;
    X = 0;
  }
  if (Y > 0 && 2 * C < B) {
    cc += 2 * Y;
    Y = 0;
  }
  cout << A * X + B * Y + cc * C << "\n";
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
