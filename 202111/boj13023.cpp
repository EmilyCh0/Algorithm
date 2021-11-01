#include <iostream>
#include <vector>
using namespace std;
int n;
vector<vector<int>> vec;
vector<bool> visit;

void DFS(int i, int cnt) {
    if (cnt == 5) {
        cout << 1;
        exit(0);
    }
    for (int j = 0; j < vec[i].size(); j++) {
        if (!visit[vec[i][j]]) {
            visit[vec[i][j]] = true;
            DFS(vec[i][j], cnt + 1);
            visit[vec[i][j]] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    cin >> n >> m;
    vec.clear();
    vec.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        visit.assign(n, false);
        visit[i] = true;
        DFS(i, 1);
    }
    cout << 0;
    return 0;
}

