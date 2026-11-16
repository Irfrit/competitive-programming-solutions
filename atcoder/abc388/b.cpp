#include <algorithm>
#include <ios>
#include <iostream>
#include <utility>
#include <vector>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int N, D;
  std::cin >> N >> D;

  std::vector<std::pair<int, int>> dimensions(N);
  while (N--) {
    int width, length;
    std::cin >> width >> length;
    dimensions[N] = {width, length};
  }
  for (int i = 1; i <= D; ++i) {
    int best = 0;
    for (const auto &snake : dimensions) {
      best = std::max(best, snake.first * (snake.second + i));
    }
    std::cout << best << '\n';
  }
}
