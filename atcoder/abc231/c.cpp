#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int N, Q;
  cin >> N >> Q;
  vector<int> h(N);
  for (int i = 0; i < N; i++) {
    cin >> h[i];
  }

  sort(h.begin(), h.end());

  while (Q--) {
    int command;
    cin >> command;
    auto lower = lower_bound(h.begin(), h.end(), command);
    cout << h.end() - lower << "\n";
  }
}
