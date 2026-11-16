#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(false);

  int N, Y;
  cin >> N >> Y;

  for (int x = 0; x <= N; x++) {
    for (int y = 0; x + y <= N; y++) {
      int z = N - x - y;
      if (10000 * x + 5000 * y + 1000 * z == Y) {
        cout << x << ' ' << y << ' ' << z << '\n';
        return 0;
      }
    }
  }
  cout << "-1 -1 -1\n";
}
