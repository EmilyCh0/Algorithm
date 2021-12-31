#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int m,n,h;
vector<vector<vector<int>>> box;
queue<pair<pair<int, int>, int>> que;
int di[] = {-1, 1, 0, 0, 0, 0};
int dj[] = {0, 0, -1, 1, 0, 0};
int dk[] = {0, 0, 0, 0, 1, -1};

void BFS() {
    vector<vector<vector<bool>>> visit(n, vector<vector<bool>>(m, vector<bool>(h, false)));

    while (!que.empty()) {
        int ii, jj, kk;
        ii = que.front().first.first;
        jj = que.front().first.second;
        kk = que.front().second;
        visit[ii][jj][kk] = true;
        que.pop();
        for (int l = 0; l < 6; l++) {
            int ni = ii + di[l];
            int nj = jj + dj[l];
            int nk = kk + dk[l];
            if (ni < 0 || nj < 0 || nk < 0 || ni >= n || nj >= m || nk >= h) {
                continue;
            }
            if (box[ni][nj][nk] == -1 || visit[ni][nj][nk] == true) {
                continue;
            }

            if (box[ni][nj][nk] == 0) {
                box[ni][nj][nk] = box[ii][jj][kk] + 1;
                que.push(make_pair(make_pair(ni, nj), nk));
                visit[ni][nj][nk] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m >> n >> h;
    box.resize(n, vector<vector<int>>(m, vector<int>(h, 0)));

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> box[j][k][i];
                if (box[j][k][i] == 1) {
                    que.push(make_pair(make_pair(j, k), i));
                }
            }
        }
    }

    BFS();

    int maxnum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < h; k++) {
                if (box[i][j][k] == 0) {
                    cout << -1;
                    return 0;
                }
                maxnum = max(maxnum, box[i][j][k]);
            }
        }
    }
    cout << maxnum - 1;

    return 0;
}

