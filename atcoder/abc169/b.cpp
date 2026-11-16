#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  long long result = 1;
  long long LIMIT = 1'000'000'000'000'000'000LL;

  vector<long long> numbers(N);
  bool has_zero = false;

  for (auto &number : numbers) {
    cin >> number;
    if (number == 0) {
      has_zero = true;
    }
  }

  if (has_zero) {
    cout << 0 << "\n";
    return 0;
  }

  for (long long number : numbers) {
    if (result > LIMIT / number) {
      cout << -1 << "\n";
      return 0;
    }
    result *= number;
  }

  cout << result << "\n";
  return 0;
}
