#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    if (n == k) {
        cout << 0 << '\n' << 1;
        return 0;
    } else if (n > k) {
        cout << n - k << '\n' << 1;
        return 0;
    }
    queue<pair<int, int>> que;
    vector<bool> visit(100001);
    que.push(make_pair(n, 0));
    int ansTime = 0;
    while (!que.empty()) {
        int idx = que.front().first;
        int cnt = que.front().second;
        que.pop();
        visit[idx] = true;
        if (idx == k) {
            ansTime = cnt;
            int ansCnt = 1;
            while (!que.empty()) {
                if (que.front().first == k && que.front().second == cnt) {
                    ansCnt++;
                }
                que.pop();
            }

            cout << ansTime << '\n';
            cout << ansCnt << '\n';
            break;
        }
        if (idx + 1 < 100001 && !visit[idx + 1]) {
            que.push(make_pair(idx + 1, cnt + 1));
        }
        if (idx - 1 >= 0 && !visit[idx - 1]) {
            que.push(make_pair(idx - 1, cnt + 1));
        }
        if (idx * 2 < 100001 && idx * 2 < k * 2 && !visit[idx * 2]) {
            que.push(make_pair(idx * 2, cnt + 1));
        }
    }

    return 0;
}