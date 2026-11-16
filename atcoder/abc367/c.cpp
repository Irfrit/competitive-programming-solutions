#include <bits/stdc++.h>
#include <numeric>

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

bool next_combination(vector<int> &a, int n, int z) {
  int k = a.size();
  for (int i = k - 1; k >= 0; k--) {
    if (a[i] <= n - k + i) {
      a[i]++;
      for (int j = i + 1; j < k; j++) {
        a[j] = a[j - 1] + 1;
      }
      if (accumulate(a.begin(), a.end(), 0) % z == 0)
        for (auto x : a)
          cout << x << ' ';
      cout << '\n';
      return true;
    }
  }
  return false;
}

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  iota(a.begin(), a.end(), 1);

  do {
  } while (next_combination(a, n, k));
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
