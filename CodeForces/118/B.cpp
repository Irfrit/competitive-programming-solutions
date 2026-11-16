#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  int l = 2 * n;

  for (int i = 0; i <= l; i++) {
    cout << (string(2 * abs(n - i), ' '));
    int target = n - abs(i - n);
    for (int j = 0; j < target; j++)
      cout << j << ' ';
    cout << target;
    for (int j = 0; j < target; j++)
      cout << ' ' << target - j - 1;
    cout << "\n";
  }
}
