#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int m,n,t;
vector<vector<int>> map;
vector<vector<bool>> visit;
queue<pair<int,int>> que;
vector<int> ans;
int di[]={-1,1,0,0};
int dj[]={0,0,-1,1};
void BFS() {
    int cnt = 1;
    while (!que.empty()) {
        int i = que.front().first;
        int j = que.front().second;
        que.pop();
        for (int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];
            if (ni < 0 || nj < 0 || ni >= n || nj >= m) {
                continue;
            }
            if (visit[ni][nj] || map[ni][nj] == -1) {
                continue;
            }
            visit[ni][nj] = true;
            que.push(make_pair(ni, nj));
            cnt++;
        }
    }
    ans.push_back(cnt);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n >> t;
    map.resize(n, vector<int>(m, 0));
    visit.resize(n, vector<bool>(m, false));

    for (int i = 0; i < t; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for (int j = a; j < c; j++) {
            for (int k = b; k < d; k++) {
                map[j][k] = -1;
                visit[j][k] = true;
            }
        }
    }
    int areaCnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visit[i][j]) {
                visit[i][j] = true;
                que.push(make_pair(i, j));
                BFS();
                areaCnt++;
            }
        }
    }
    cout<<areaCnt<<"\n";
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
