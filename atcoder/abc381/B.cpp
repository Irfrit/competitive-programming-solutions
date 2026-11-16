#include <ios>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string input;

  cin >> input;
  int T = input.length();

  if (T % 2 != 0) {
    cout << "No" << "\n";
    return 0;
  }

  for (int i = 0; i < T / 2; i++) {
    if (input[2 * i] != input[2 * i + 1]) {
      cout << "No" << "\n";
      return 0;
    }
  }
  map<char, int> cnt;

  for (char c : input)
    cnt[c]++;

  bool ok = true;

  for (auto &[ch, n] : cnt) {
    if (n != 2)
      ok = false;
  }
  cout << (ok ? "Yes" : "No") << "\n";
  return 0;
}
