#include <bits/stdc++.h>
#include <climits>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<long long> nums(n);

  for (auto &num : nums) {
    cin >> num;
  }
  long long curr_max = nums[0], global_max = nums[0];
  for (int i = 1; i < n; i++) {
    curr_max = max(nums[i], curr_max + nums[i]);
    global_max = max(curr_max, global_max);
  }

  cout << global_max << "\n";
  return 0;
}
