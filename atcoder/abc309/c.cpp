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
  int N, K;
  cin >> N >> K;
  vector<pair<int, int>> A;
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    A.push_back({1, b});
    A.push_back({a + 1, -b});
  }
  sort(all(A));
  ll running_total = 0;

  for (int i = 0; i < sz(A);) {
    ll day = A[i].first;
    ll delta = 0;

    while (i < sz(A) && A[i].first == day) {
      delta += A[i].second;
      i++;
    }

    running_total += delta;
    if (running_total <= K) {
      cout << day << "\n";
      break;
    }
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
