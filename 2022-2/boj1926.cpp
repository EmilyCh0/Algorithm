#include "iostream"
#include "vector"
#include "queue"
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> vec(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> vec[i][j];
        }
    }
    int di[] = {1, -1, 0, 0};
    int dj[] = {0, 0, 1, -1};
    int maxSize = 0;
    int cnt = 0;

    queue<pair<int, int>> que;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vec[i][j] == 0)
                continue;
            que.push(make_pair(i, j));
            vec[i][j] = 0;
            int size = 1;
            cnt++;
            while (!que.empty()) {
                int ii = que.front().first;
                int jj = que.front().second;
                que.pop();
                for (int k = 0; k < 4; k++) {
                    int ni = ii + di[k];
                    int nj = jj + dj[k];
                    if (ni < 0 || nj < 0 || ni >= n || nj >= m)
                        continue;
                    if (vec[ni][nj] == 1) {
                        size++;
                        que.push(make_pair(ni, nj));
                        vec[ni][nj] = 0;
                    }
                }
            }
            maxSize = max(maxSize, size);
        }
    }

    cout << cnt << '\n' << maxSize;

    return 0;
}

