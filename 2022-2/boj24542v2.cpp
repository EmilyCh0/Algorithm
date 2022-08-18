#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> vec;
vector<bool> isUsed;
int n,m;

int BFS(int i) {
    queue<int> que;
    que.push(i);
    isUsed[i] = true;
    int cnt = 1;
    while (!que.empty()) {
        int now = que.front();
        que.pop();
        for (int tmp: vec[now]) {
            if (isUsed[tmp]) continue;
            que.push(tmp);
            isUsed[tmp] = true;
            cnt++;
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    vec.assign(n + 1, vector<int>());
    isUsed.assign(n + 1, false);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    long long ans = 1;
    for (int i = 1; i <= n; i++) {
        if (!isUsed[i]) {
            ans = (ans * (long long) BFS(i)) % 1000000007;
        }
    }
    cout << ans;
    return 0;
}