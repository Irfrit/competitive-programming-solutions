#include <bits/stdc++.h>
#include <cinttypes>
#include <unordered_map>

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
  int n, x;
  cin >> n >> x;

  vector<int> a(n);

  for (int &p : a) {
    cin >> p;
  }

  sort(all(a));
  int i = 0, j = n - 1;
  int result = 0;

  while (i <= j) {
    if (i < j && a[i] + a[j] <= x) {
      i++;
    }
    j--;
    result++;
  }

  cout << result << "\n";
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
