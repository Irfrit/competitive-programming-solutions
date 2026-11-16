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

void solve(int l, int r, string &S) {
  int result = 0;

  for (int p = l + 1; p <= r; p++) {
    if (S[p - 1] == S[p - 2])
      result++;
  }
  cout << result << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, Q;
  string S;
  cin >> N >> Q;
  cin >> S;
  vector<int> pre(N + 1);

  for (int i = 2; i <= N; i++) {
    pre[i] = pre[i - 1] + (S[i - 2] == S[i - 1]);
  }

  while (Q--) {
    int l, r;
    cin >> l >> r;
    cout << pre[r] - pre[l] << "\n";
  }

  return 0;
}
