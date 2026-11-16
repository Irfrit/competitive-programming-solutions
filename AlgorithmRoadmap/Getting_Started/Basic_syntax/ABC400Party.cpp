#include <iostream>

int main() {
  int A;
  std::cin >> A;
  if (400 % A == 0) {
    std::cout << 400 / A;
  } else {
    std::cout << -1;
  }
  return 0;
}
