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

void flip(vector<pair<int, int>> &stack, int k, int n) {
  vector<pair<int, int>> reversed(k);
  for (int i = 0; i < k; i++) {
    auto [value, flip] = stack[k - i - 1];
    reversed[i] = {value, 1 - flip};
  }
  copy(reversed.begin(), reversed.end(), stack.begin());
}

void solve() {
  int N, Q;
  cin >> N >> Q;
  vector<pair<int, int>> stack(N);
  for (int i = 0; i < N; i++) {
    stack[i] = {i + 1, 0};
  }
  for (int i = 0; i < Q; i++) {
    int k;
    cin >> k;
    flip(stack, k, N);
  }

  for (auto row : stack) {
    cout << (row.second ? -row.first : row.first) << "\n";
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
