#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {

  cin.tie(0)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> p(n + 1, 0);
    vector<long long> s(n + 1, 0);

    for (auto &x : a)
      cin >> x;

    for (int i = 1; i < n; i++) {
      p[i + 1] = p[i] + abs(a[i]);
    }

    for (int i = n - 1; i >= 0; i--) {
      s[i] = s[i + 1] + a[i];
    }
    long long res = -s[1];

    for (int i = 1; i < n; i++) {
      long long result = a[0] + p[i] - s[i + 1];
      res = max(res, result);
    }
    cout << res << "\n";
  }
}
