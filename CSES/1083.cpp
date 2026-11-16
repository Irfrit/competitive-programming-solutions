#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;

  long long target = 1LL * n * (n + 1) / 2;
  for (int i = 0; i < n - 1; ++i) {
    int x;
    cin >> x;
    target -= x;
  }

  cout << target;
}
