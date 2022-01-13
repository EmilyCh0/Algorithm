#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
int di[] = {-1,1,0,0};
int dj[] = {0,0,-1,1};
int cnt;
vector<vector<int>> map;
vector<pair<int,int>> blank;
vector<pair<int,int>> virus;

int BFS() {
    queue<pair<int, int>> que;
    vector<vector<bool>> visit(n, vector<bool>(m));
    int safeCnt = cnt - 3;
    for (int i = 0; i < virus.size(); i++) {
        que.push(virus[i]);
        visit[virus[i].first][virus[i].second] = true;
    }
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
                safeCnt--;
            }
        }
    }
    return safeCnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie();
    cin >> n >> m;
    map.resize(n, vector<int>(m));
    cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 0) {
                blank.push_back(make_pair(i, j));
                cnt++;
            } else if (map[i][j] == 2) {
                virus.push_back(make_pair(i, j));
            }
        }
    }
    int maxNum = 0;
    for (int i = 0; i < blank.size() - 2; i++) {
        for (int j = i + 1; j < blank.size() - 1; j++) {
            for (int k = j + 1; k < blank.size(); k++) {
                map[blank[i].first][blank[i].second] = 1;
                map[blank[j].first][blank[j].second] = 1;
                map[blank[k].first][blank[k].second] = 1;
                int tmp = BFS();
                maxNum = max(maxNum, tmp);
                map[blank[i].first][blank[i].second] = 0;
                map[blank[j].first][blank[j].second] = 0;
                map[blank[k].first][blank[k].second] = 0;
            }
        }
    }
    cout << maxNum;

    return 0;
}