#include <bits/stdc++.h>

using namespace std;

long long MOD = 1'000'000'007;
long long dp[1000006];

int main() {
  cin.tie(0)->sync_with_stdio(false);

  int N;
  cin >> N;
  dp[0] = 1;
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= 6; j++) {
      if (i - j >= 0) {
        dp[i] += dp[i - j];
      }
    }
    dp[i] %= MOD;
  }
  cout << dp[N];
  return 0;
}
