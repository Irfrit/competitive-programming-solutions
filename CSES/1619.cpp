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
  int n;
  cin >> n;
  vector<pair<ll, int>> events;

  for (int i = 0; i < n; i++) {
    ll l, r;
    cin >> l >> r;
    events.push_back({l, 1});
    events.push_back({r, -1});
  }

  int current = 0;
  int result = 0;
  sort(all(events));
  for (auto [time, diff] : events) {
    current += diff;
    result = max(result, current);
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
