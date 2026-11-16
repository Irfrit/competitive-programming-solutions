
#include <bits/stdc++.h>
#include <vector>

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
  int n, m;
  int best = INT_MIN;
  vector<int> segs;
  vector<int> ans_best;
  cin >> n >> m;
  vector<int> arr(n);
  for (auto &a : arr)
    cin >> a;
  vector<pair<int, int>> segments(m);
  for (auto &[l, r] : segments)
    cin >> l >> r;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      vector b = arr;
      vector<int> ans;
      // int result =  max(arr[i],arr[j]) + min(arr[i],arr[j]);
      for (int k = 0; k < m; k++) {
        bool has_i = segments[k].first - 1 <= i && i <= segments[k].second - 1;
        bool has_j = segments[k].first - 1 <= j && j <= segments[k].second - 1;
        if (has_j && !has_i)
          ans.push_back(k);
      }

      int result = arr[i] - arr[j] + (int)ans.size();
      if (result > best) {
        best = result;
        ans_best = ans;
      }
    }
  }
  cout << best << "\n" << ans_best.size() << "\n";
  for (int k : ans_best)
    cout << k + 1 << ' ';
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
