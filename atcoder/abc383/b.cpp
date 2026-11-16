#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w, d;
    cin >> h >> w >> d;
    vector<string> grid(h);
    for (auto &row : grid) cin >> row;

    vector<pair<int, int>> floors;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if (grid[i][j] == '.')
                floors.emplace_back(i, j);

    int ans = 0;
    int f = floors.size();
    for (int a = 0; a < f; a++) {
        for (int b = a + 1; b < f; b++) {
            int count = 0;
            for (auto [i, j] : floors) {
                int da = abs(i - floors[a].first) + abs(j - floors[a].second);
                int db = abs(i - floors[b].first) + abs(j - floors[b].second);
                if (da <= d || db <= d) count++;
            }
            ans = max(ans, count);
        }
    }
    cout << ans << '\n';
    return 0;
}
