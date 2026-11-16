#include <ios>
#include <iostream>
#include <vector>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::vector<int> seen(14);

  int unique_seen = 0;
  for (int i = 0; i < 4; ++i) {
    int number;
    std::cin >> number;
    if (seen[number] == 0) {
      unique_seen++;
    }
    seen[number]++;
    if (seen[number] >= 4 || unique_seen >= 3) {
      std::cout << "No";
      return 0;
    }
  }

  std::cout << "Yes";
}
