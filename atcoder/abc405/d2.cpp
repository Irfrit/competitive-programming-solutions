#include <iostream>
#include <pthread.h>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int H, W;
  cin >> H >> W;

  vector<string> Cinema(H);
  for (auto &row : Cinema) {
    cin >> row;
  }

  vector<vector<int>> dist(H, vector<int>(W, -1));
  queue<pair<int, int>> q;

  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      if (Cinema[i][j] == 'E') {
        dist[i][j] = 0;
        q.push({i, j});
      }
    }
  }

  const int di[] = {-1, 1, 0, 0};

  const int dj[] = {0, 0, -1, 1};

  while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop();
    for (int d = 0; d < 4; d++) {
      int ni = i + di[d];
      int nj = j + dj[d];
      if (ni < 0 || ni >= H || nj < 0 || nj >= W)
        continue;
      if (Cinema[ni][nj] != '.' || dist[ni][nj] != -1)
        continue;

      dist[ni][nj] = dist[i][j] + 1;
      q.push({ni, nj});
    }
  }

  const char dir[] = {'^', 'v', '<', '>'};
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (Cinema[i][j] != '.' || dist[i][j] == -1)
        continue;
      for (int d = 0; d < 4; d++) {

        int ni = i + di[d];
        int nj = j + dj[d];

        if (ni < 0 || ni >= H || nj < 0 || nj >= W)
          continue;
        if (dist[ni][nj] == dist[i][j] - 1) {
          Cinema[i][j] = dir[d];
          break;
        }
      }
    }
  }

  for (auto &row : Cinema) {
    cout << row << '\n';
  }
  return 0;
}
