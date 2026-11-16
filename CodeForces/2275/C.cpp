#include <bits/stdc++.h>
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
  int n;
  cin >> n;
  vector<long long> a(n);
  for (auto &cell : a)
    cin >> cell;
  unordered_map<long long, long long> freq;
  long long ans = 0;

  for (int i = 0; i < n - 4; i++) {
    ll sum = a[i] + a[i + 2] - a[i + 4];

    ans += freq[sum];
    if (i >= 2) {
      ll s = a[i - 2] + a[i] - a[i + 2];
      if (s == sum)
        ans--;
    }

    if (i >= 4) {
      ll s = a[i - 4] + a[i - 2] - a[i];
      if (s == sum)
        ans--;
    }

    freq[sum]++;
  }

  cout << ans << "\n";
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
