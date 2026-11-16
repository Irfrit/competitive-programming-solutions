#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  long long n;
  cin >> n;
  vector<long long> mod(200, 0);

  while (n--) {
    long long x;
    cin >> x;
    mod[x % 200]++;
  }

  long long result = 0;
  for (auto x : mod) {
    result += x * (x - 1) / 2;
  }

  cout << result << "\n";
  return 0;
}
