#include <bits/stdc++.h>
#include <ios>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  while (N--) {
    string s;
    cin >> s;
    vector<int> blocks;
    int curr_count = 1;

    for (int i = 1; i < (int)s.size(); ++i) {
      if (s[i] == s[i - 1]) {
        ++curr_count;
      } else {
        blocks.push_back(curr_count);
        curr_count = 1;
      }
    }
    blocks.push_back(curr_count);

    bool has_Single = false;
    bool has_over_three = false;
    int k = blocks.size();

    for (int i = 0; i < k; i++) {
      if (blocks[i] >= 3)
        has_over_three = true;
      if (i > 0 && i < k - 1 && blocks[i] == 1) {
        has_Single = true;
      }
    }
    cout << 1 + has_Single + has_over_three << "\n";
  }
  return 0;
}
