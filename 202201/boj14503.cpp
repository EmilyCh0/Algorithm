#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> map;

int n, m;
vector<vector<int>> dr={{0,1,0,-1},{-1,0,1,0},{0,-1,0,1},{1,0,-1,0}};
vector<vector<int>> dc={{-1,0,1,0},{0,-1,0,1},{1,0,-1,0},{0,1,0,-1}};
int ans=1;

void clean(int r, int c, int d) {
    map[r][c] = -1;
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[d][i];
        int nc = c + dc[d][i];
        if (nr < 0 || nc < 0 || nr >= n || nc >= m) {
            continue;
        }
        if (map[nr][nc] == 0) {
            ans++;
            clean(nr, nc, (d - i + 3) % 4);
        }
    }
    int nr = r + dr[d][1];
    int nc = c + dc[d][1];
    if (nr < 0 || nc < 0 || nr >= n || nc >= m) {
        return;
    }
    if (map[nr][nc] == 1) {
        cout << ans;
        exit(0);
    } else {
        clean(nr, nc, d);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    int r, c, d;
    cin >> r >> c >> d;
    map.assign(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    clean(r, c, d);

    cout << ans;

    return 0;
}
