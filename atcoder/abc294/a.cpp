#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int N, Q;
  cin >> N >> Q;
  vector<int> gone(N + 1);
  int ans = 1;

  while (Q--) {
    int event;
    cin >> event;

    if (event == 1) {
    } else if (event == 2) {
      int x;
      cin >> x;
      gone[x] = 1;
    } else {
      while (gone[ans])
        ans++;
      cout << ans << '\n';
    }
  }
}
