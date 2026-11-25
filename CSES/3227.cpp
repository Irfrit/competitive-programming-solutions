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
  int n, k;
  cin >> n >> k;
  vector<int> heights(n);
  vector<int> left(n, -1);
  for (auto &x : heights)
    cin >> x;
  stack<int> st;
  for (int i = 0; i < n; i++) {
    while (!st.empty() && heights[st.top()] >= heights[i]) {
      st.pop();
    }
    left[i] = st.empty() ? -1 : st.top();
    st.push(i);
  }
  vector<int> right(n, n);
  st = stack<int>();
  for (int i = n - 1; i >= 0; i--) {
    while (!st.empty() && heights[st.top()] >= heights[i]) {
      st.pop();
    }
    right[i] = st.empty() ? n : st.top();
    st.push(i);
  }

  vector<ll> res(n - k + 1);

  for (int i = 0; i <= n - k; i++) {
    ll area = 0;
    int l = i, r = l + k;
    for (int j = i; j < r; j++) {
      int width = min(r, right[j]) - max(l, left[j] + 1);
      ckmax(area, 1LL * width * heights[j]);
    }
    res[i] = area;
  }

  for (int i = 0; i <= n - k; i++) {
    if (i)
      cout << ' ';
    cout << res[i];
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
