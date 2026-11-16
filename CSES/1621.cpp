#include <bits/stdc++.h>
#include <linux/limits.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  set<int> nums;

  while (n--) {
    int x;
    cin >> x;
    nums.insert(x);
  }
  cout << nums.size() << "\n";
  return 0;
}
