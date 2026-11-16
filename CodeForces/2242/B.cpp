#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> pref1(n + 1, 0);
    vector<int> pref2(n + 1, 0);

    for (int &number : a) {
      cin >> number;
    }
    for (int i = 0; i < n; i++) {
      pref1[i + 1] = pref1[i] + (a[i] == 1 ? 1 : -1);
      pref2[i + 1] = pref2[i] + (a[i] == 3 ? -1 : 1);
    }
    int mn = INT_MAX;
    bool found = false;

    for (int i = 1; i < n; ++i) {
      if (mn != INT_MAX && pref2[i] >= mn) {
        found = true;
        break;
      }
      if (pref1[i] >= 0) {
        mn = min(mn, pref2[i]);
      }
    }
    cout << (found ? "YES" : "NO") << "\n";
  }
  return 0;
}
