#include <ios>
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  long long a1, a2;
  cin >> N;
  cin >> a1 >> a2;

  for (int i = 2; i < N; ++i) {
    long long number;
    cin >> number;
    if (a2 * a2 != a1 * number) {
      cout << "No";
      return 0;
    }
    a1 = a2;
    a2 = number;
  }
  cout << "Yes";
  return 0;
}
