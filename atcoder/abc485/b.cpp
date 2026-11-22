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
  int N, M;
  cin >> N >> M;
  vector<bool> faucets(N), drains(M, false);
  for (int i = 0; i < N; i++) {
    string S;
    cin >> S;
    if (S == string(M, 'x')) {
      cout << "Faucet " << i + 1 << "\n";
      return;
    }
    for (int j = 0; j < M; j++) {
      if (S[j] == 'o') {
        drains[j] = true;
      }
    }
  }

  for (int i = 0; i < M; i++) {
    if (!drains[i]) {
      cout << "Drain " << i + 1 << "\n";
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
