#include <bits/stdc++.h>
#include <tuple>

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

int n;
vector<ll> apples;

ll solution(int index, ll sum1, ll sum2) {
  if (index == n)
    return abs(sum1 - sum2);

  return (min(solution(index + 1, sum1 + apples[index], sum2),
              solution(index + 1, sum1, sum2 + apples[index])));
}
void solve() {
  cin >> n;
  apples.resize(n);
  for (auto &apple : apples)
    cin >> apple;
  cout << solution(0, 0, 0) << "\n";
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
