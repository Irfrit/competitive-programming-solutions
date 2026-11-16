#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  long long s;
  cin >> n >> s;

  long long sum = s;

  map<long long, long long> Radius;
  while (n--) {
    int x, y, k;
    cin >> x >> y >> k;
    Radius[x * x + y * y] += k;
  }

  for (auto [radius, cnt] : Radius) {
    sum += cnt;
    if (sum >= 1000000) {
      cout << fixed << setprecision(7) << sqrt(radius);
      return 0;
    }
  }
  cout << -1;
}
