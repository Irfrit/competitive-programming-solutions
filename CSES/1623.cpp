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

ll recursive_apple(int index, ll sum1, ll sum2, int n, vector<ll> &weights) {
  if (index == n)
    return abs(sum1 - sum2);

  return min(
      recursive_apple(index + 1, sum1, sum2 + weights[index], n, weights),
      recursive_apple(index + 1, sum1 + weights[index], sum2, n, weights));
}

void solve() {
  int n;
  cin >> n;
  vector<ll> weights(n);
  for (int i = 0; i < n; i++)
    cin >> weights[i];

  cout << recursive_apple(0, 0, 0, n, weights) << "\n";
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
