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
  int N, M;
  cin >> N >> M;
  vector<int> a(N + 1);
  vector<pair<int, int>> voters(M);
  vector<int> winners(N + 1);
  for (int i = 0; i <= N; i++) {
    winners[i] = i;
  }
  for (auto &vote : voters) {
    int A, B;
    cin >> A >> B;
    vote = {A, B};
    a[A]++;
  }

  for (int withdraw = 1; withdraw <= N; withdraw++) {
    vector<int> votes = a;

    for (auto row : voters) {
      if (row.first == withdraw) {
        votes[row.first]--;
        votes[row.second]++;
      }
    }
    int win = 0;
    for (int cand = 1; cand <= N; cand++) {
      if (cand == withdraw)
        continue;

      if (win == 0 || votes[cand] > votes[win]) {
        win = cand;
      }
    }
    winners[withdraw] = win;
  }

  for (int i = 1; i <= N; i++) {
    cout << winners[i] << "\n";
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
