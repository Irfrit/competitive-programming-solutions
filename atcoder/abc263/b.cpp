#include <bits/stdc++.h>

using namespace std;
int main() {
  cin.tie(0)->sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> a(N + 1);
  int result = 0;
  for (int i = 2; i <= N; i++) {
    int x;
    cin >> x;
    a[i] = x;
  }

  int cur = N;
  while (cur != 1) {
    result++;
    cur = a[cur];
  }
  cout << result;
}
