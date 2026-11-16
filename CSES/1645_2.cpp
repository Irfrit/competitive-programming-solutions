#include <ios>
#include <iostream>
#include <stack>
using namespace std;

int main() {
  cin.tie(0)->ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  stack<pair<int, int>> stack;

  stack.push({0, 0});

  for (int i = 1; i <= N; ++i) {
    int a;
    cin >> a;
    while (!stack.empty() && stack.top().first >= a)
      stack.pop();
    cout << stack.top().second << " ";
    stack.push({a, i});
  }
}
