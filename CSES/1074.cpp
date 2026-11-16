#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ios>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;
  vector<long long> input(N);
  for (int i = 0; i < N; i++) {
    cin >> input[i];
  }

  sort(input.begin(), input.end());
  long long median = input[N / 2];

  long long price = 0;
  for (int i = 0; i < N; i++) {
    price += abs(median - input[i]);
  }

  cout << price;
}
