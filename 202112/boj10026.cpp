#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int n;
vector<vector<char>> map;
vector<vector<bool>> visit;

int di[] = {-1,1,0,0};
int dj[] = {0,0,1,-1};

void BFS(int i, int j) {
    queue<pair<int, int>> que;
    que.push(make_pair(i, j));
    visit[i][j] = true;
    while (!que.empty()) {
        int ii = que.front().first;
        int jj = que.front().second;
        que.pop();

        for (int k = 0; k < 4; k++) {
            int ni = ii + di[k];
            int nj = jj + dj[k];
            if (ni < 0 || nj < 0 || ni >= n || nj >= n) {
                continue;
            }
            if (!visit[ni][nj]) {
                if (map[ni][nj] == map[i][j]) {
                    visit[ni][nj] = true;
                    que.push(make_pair(ni, nj));
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie();
    cin >> n;
    map.resize(n, vector<char>(n));
    visit.resize(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < n; j++) {
            map[i][j] = tmp[j];

        }
    }

    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visit[i][j]) {
                BFS(i, j);
                cnt1++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 'G') {
                map[i][j] = 'R';
            }
        }
    }
    visit.assign(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visit[i][j]) {
                BFS(i, j);
                cnt2++;
            }
        }
    }
    cout << cnt1 << " " << cnt2;

    return 0;
}

