#include <algorithm>
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
bool isPrime(int n) {
  if (n <= 1)
    return false;
  if (n == 2)
    return true;
  if (n % 2 == 0)
    return false;

  for (int i = 3; i <= std::sqrt(n); i += 2) {
    if (n % i == 0)
      return false;
  }
  return true;
}
void solve() {
  int n;
  cin >> n;

  if (n < 4) {
    cout << -1 << " ";
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (i == 1) {
      cout << 4 << " ";
    } else if (i == 4)
      cout << 1 << ' ';
    else {
      cout << i << " ";
    }
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
