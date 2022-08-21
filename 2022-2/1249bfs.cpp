#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<vector<int>> map;
vector<vector<int>> cost;
int di[] = {1,-1,0,0};
int dj[] = {0,0,1,-1};

void BFS() {
    queue<pair<int, int>> que;
    que.push({0, 0});
    cost[0][0] = 0;
    while (!que.empty()) {
        int ii = que.front().first;
        int jj = que.front().second;
        que.pop();
        for (int k = 0; k < 4; k++) {
            int ni = ii + di[k];
            int nj = jj + dj[k];
            if (ni < 0 || nj < 0 || ni >= n || nj >= n) continue;
            if (cost[ni][nj] > cost[ii][jj] + map[ni][nj]) {
                cost[ni][nj] = cost[ii][jj] + map[ni][nj];
                que.push({ni, nj});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        cin >> n;
        map.assign(n, vector<int>(n));
        cost.assign(n, vector<int>(n, 1e9));
        for (int i = 0; i < n; i++) {
            string str;
            cin >> str;
            for (int j = 0; j < n; j++) {
                map[i][j] = str[j] - '0';
            }
        }
        BFS();
        cout << "#" << tc << " " << cost[n - 1][n - 1] << "\n";
    }

    return 0;
}