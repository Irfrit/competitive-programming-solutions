#include <iostream>

int main() {
  int l = 1;
  int r;
  std::cin >> r;
  r++;

  while (l + 1 != r) {
    int mid = (l + r) / 2;
    std::cout << '?' << mid << '\n';
    int ans;
    std::cin >> ans;
    if (ans) {
      r = mid;
    } else {
      l = mid;
    }
  }

  std::cout << '!' << l << '\n';
}
