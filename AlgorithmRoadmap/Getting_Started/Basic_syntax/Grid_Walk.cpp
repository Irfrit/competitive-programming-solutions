#include <ios>
#include <iostream>
#include <string>
#include <type_traits>
#include <vector>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int H, W;
  std::cin >> H >> W;
  std::vector<std::string> matrix(H);
  int Si, Ji;
  std::cin >> Si >> Ji;
  Si--;
  Ji--;

  for (int i = 0; i < H; ++i) {
    std::cin >> matrix[i];
  }

  std::string X;
  std::cin >> X;

  for (auto const &move : X) {
    switch (move) {
    case 'L':
      if (Ji > 0 && matrix[Si][Ji - 1] == '.') {
        Ji--;
      }
      break;

    case 'R':
      if (Ji + 1 < W && matrix[Si][Ji + 1] == '.') {
        Ji++;
      }
      break;

    case 'U':
      if (Si > 0 && matrix[Si - 1][Ji] == '.') {
        Si--;
      }
      break;

    case 'D':
      if (Si + 1 < H && matrix[Si + 1][Ji] == '.') {
        Si++;
      }
      break;
    }
  }
  std::cout << Si + 1 << ' ' << Ji + 1 << '\n';
}
