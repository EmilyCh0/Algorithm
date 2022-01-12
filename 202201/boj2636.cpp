#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
int cheese = 0;
vector<vector<int>> map;
int di[]={0,0,-1,1};
int dj[]={-1,1,0,0};


int BFS(int i, int j) {
    vector<vector<bool>> visit(n, vector<bool>(m, false));
    queue<pair<int, int>> que;
    que.push(make_pair(i, j));
    visit[i][j] = true;
    int cnt = 0;
    while (!que.empty()) {
        int ii = que.front().first;
        int jj = que.front().second;
        que.pop();
        for (int k = 0; k < 4; k++) {
            int ni = ii + di[k];
            int nj = jj + dj[k];
            if (ni < 0 || nj < 0 || ni >= n || nj >= m) {
                continue;
            }
            if (visit[ni][nj]) {
                continue;
            }
            if (map[ni][nj] == 0) {
                que.push(make_pair(ni, nj));
                visit[ni][nj] = true;
            } else {
                cheese--;
                cnt++;
                map[ni][nj] = 0;
                visit[ni][nj] = true;
            }
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    map.resize(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1) {
                cheese++;
            }
        }
    }

    int ans = 0;
    int tmp;
    while (cheese > 0) {
        tmp = BFS(0, 0);
        ans++;
    }
    cout << ans << '\n' << tmp;

    return 0;
}
