#include <bits/stdc++.h>
#include <regex>

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

struct Restaurant {
  string City;
  int Score;
  auto operator<(const Restaurant &other) const {
    if (City != other.City)
      return City < other.City;
    return Score > other.Score;
  }
};

void solve() {
  int n;
  cin >> n;
  vector<pair<Restaurant, int>> a;
  for (int i = 1; i <= n; i++) {
    string s;
    int p;
    cin >> s >> p;
    a.push_back({{s, p}, i});
  }
  sort(all(a));
  for (auto [rest, index] : a) {
    cout << index << "\n";
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
