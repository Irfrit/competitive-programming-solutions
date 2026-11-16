#include <ios>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;
  vector<int> result(N + 1);
  vector<int> input(N + 1);
  int number;

  for (int i = 1; i <= N; i++) {
    cin >> input[i];
  }

  for (int i = N; i >= 1; i--) {
    if (input[i] == i) {
      result[i] = i;
    } else {
      result[i] = result[input[i]];
    }
  }

  for (int i = 1; i <= N; ++i) {
    if (i > 1) {
      std::cout << ' ';
    }
    std::cout << result[i];
  }
  std::cout << '\n';
}
