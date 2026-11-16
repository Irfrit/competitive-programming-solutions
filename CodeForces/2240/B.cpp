#include <ios>
#include <iostream>

using namespace std;

long long power(long long x, long long y, long long mod) {
  long long result = 1;
  x %= mod;
  while (y > 0) {
    if (y % 2 == 1) {
      result = (result * x) % mod;
    }
    x = (x * x) % mod;
    y /= 2;
  }
  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  long long MOD = 998244353;

  int N;
  cin >> N;

  while (N--) {
    long long a, b, c, d;

    cin >> a >> b >> c >> d;

    cout << power(2, (a * b - (a - c + 1) * (b - d + 1)), MOD) << "\n";
  }
  return 0;
}
