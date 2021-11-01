#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int boj17086() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> res(n, vector<int>(m, 0));
    queue<pair<int, int>> que;
    int tmp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> tmp;
            if (tmp == 1) {
                que.push(make_pair(i, j));
                res[i][j] = 1;
            }
        }
    }
    int di[] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dj[] = {0, 0, -1, 1, -1, 1, -1, 1};
    while (!que.empty()) {
        int i = que.front().first;
        int j = que.front().second;
        que.pop();
        for (int k = 0; k < 8; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];
            if (ni < 0 || nj < 0 || ni >= n || nj >= m) {
                continue;
            }
            if (res[ni][nj] == 0) {
                res[ni][nj] = res[i][j] + 1;
                que.push(make_pair(ni, nj));
            } else if (res[ni][nj] > res[i][j] + 1) {
                res[ni][nj] = res[i][j] + 1;
                que.push(make_pair(ni, nj));
            }
        }
    }
    int max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (res[i][j] > max) {
                max = res[i][j];
            }
        }
    }
    cout << max - 1;

    return 0;
}

