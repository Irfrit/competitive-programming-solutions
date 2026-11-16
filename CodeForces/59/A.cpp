#include <algorithm>
#include <cctype>
#include <cinttypes>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string S;
  cin >> S;
  int up = 0;
  int low = 0;

  for (auto letter : S) {
    if (isupper(letter)) {
      up++;
    } else {
      low++;
    }
  }
  if (up == low || low > up) {
    transform(S.begin(), S.end(), S.begin(),
              [](unsigned char c) { return tolower(c); });
  } else {
    transform(S.begin(), S.end(), S.begin(),
              [](unsigned char c) { return toupper(c); });
  }

  cout << S;
  return 0;
}
