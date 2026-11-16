#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ar = array<int, 2>;
using db = double;

#define all(x) (x).begin(), (x).end()
#define sz(x) static_cast<int>((x).size())

template <typename T> bool ckmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return true;
  }
  return false;
}

template <typename T> bool ckmax(T &a, const T &b) {
  if (b > a) {
    a = b;
    return true;
  }
  return false;
}

void solve() {
  int N, M, Q;
  int result = 0;
  cin >> N >> M >> Q;
  vector<pair<int, int>> baggage(N);
  vector<int> boxes(M);
  for (auto &[w, v] : baggage)
    cin >> w >> v;
  for (auto &box : boxes)
    cin >> box;

  sort(all(baggage),
       [&](const auto a, const auto b) { return a.second > b.second; });

  while (Q--) {
    int L, R;
    result = 0;
    cin >> L >> R;
    vector<int> avaiable(boxes.begin(), boxes.begin() + (L - 1));
    avaiable.insert(avaiable.end(), boxes.begin() + R, boxes.end());
    sort(all(avaiable));

    for (auto bag : baggage) {
      for (int i = 0; i < sz(avaiable); i++) {
        if (avaiable[i] >= bag.first) {
          result += bag.second;
          avaiable.erase(avaiable.begin() + i);
          break;
        }
      }
    }
    cout << result << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  // cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
