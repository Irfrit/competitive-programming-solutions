#include <algorithm>
#include <bits/stdc++.h>
#include <string>
#include <string_view>

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

bool isInsade(string_view a, string_view b) {
  if (a.size() > b.size())
    return false;

  for (int i = 0; i <= b.size() - a.size(); i++) {
    if (b.substr(i, a.size()) == a)
      return true;
  }
  return false;
}

int overlap(string_view a, string_view b) {
  int limit = min(a.size(), b.size());

  for (int i = limit; i > 0; i--) {
    if (a.substr(a.size() - i) == b.substr(0, i)) {
      return i;
    }
  }
  return 0;
}

void solve() {

  vector<string> a(3);
  for (auto &x : a)
    cin >> x;
  vector<bool> remove(3, 0);

  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < a.size(); j++) {
      if (i == j)
        continue;
      if (i > j && a[i] == a[j]) {
        remove[j] = true;
        break;
      }
      if (isInsade(a[i], a[j])) {
        remove[i] = true;
        break;
      }
    }
  }
  vector<string> temp;
  for (int i = 0; i < a.size(); i++) {
    if (remove[i] == false)
      temp.push_back(a[i]);
  }

  a = move(temp);

  sort(all(a));

  int lenght = 0;
  for (auto x : a) {
    lenght += x.size();
  }

  int best = lenght;

  do {
    int result = lenght;
    for (int i = 1; i < a.size(); i++) {
      result -= overlap(a[i - 1], a[i]);
    }
    best = min(best, result);
  } while (next_permutation(all(a)));

  cout << best << "\n";
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
