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
  int N;
  string S;
  cin >> N >> S;
  set<char> left, right;
  left.emplace(S[0]);
  int i = 0;
  while (sz(left) != 3) {
    left.emplace(S[i]);
    i++;
  }

  int j = N - 1;
  right.emplace(S[j]);
  while (sz(right) != 3) {
    right.emplace(j);
    j--;
  }
  set<char> mid;
  int k = i + 1;
  while (sz(mid) == 3) {
    mid.emplace(k);
    k++;
  }
  cout << max(0, j - k + 1) << "\n";
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
