#include <bits/stdc++.h>

using namespace std;

long long dp[1000001];
int main() {
  cin.tie(0)->sync_with_stdio(false);
  int N;
  cin >> N;

  dp[0] = 1;
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= 6; j++) {
      if (i - j >= 0) {
        dp[i] = dp[i] + dp[i - j];
      }
    }
    dp[i] %= 1000000007;
  }
  cout << dp[N] << "\n";
  return 0;
}
