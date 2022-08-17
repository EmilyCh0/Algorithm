#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> parent;

int findParent(int a) {
    if (a == parent[a]) return a;
    return parent[a] = findParent(parent[a]);
}

void group(int a, int b) {
    int pa = findParent(a);
    int pb = findParent(b);
    if (pa != pb) {
        parent[b] = pa;
        for (int i = 1; i <= n; i++) {
            if (parent[i] == pb) parent[i] = pa;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    parent.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    vector<vector<int>> party(m);

    int t;
    cin >> t;
    if (t == 0) { // 진실을 아는 사람이 없으면
        cout << m;
        return 0;
    } else if (t == n) { // 모두 진실을 알고있으면
        cout << 0;
        return 0;
    }
    vector<int> knowList(t); // 진실을 아는 사람 목록
    for (int i = 0; i < t; i++) {
        cin >> knowList[i];
    }
    // union-find 그룹핑
    for (int i = 0; i < m; i++) {
        int num, mem;
        cin >> num;
        for (int j = 0; j < num; j++) {
            cin >> mem;
            party[i].push_back(mem);
        }
        int tmpP = party[i][0];
        for (int j = 1; j < num; j++) {
            group(tmpP, party[i][j]);
        }
    }

    vector<bool> know(n + 1, false); // 진실을 아는지 체크
    for (int i: knowList) {
        int p = findParent(i); // 진실을 아는 사람의 부모(p)를 찾고,
        know[p] = true;
        for (int j = 1; j <= n; j++) {
            if (parent[j] == p) know[j] = true; // p 그룹에 속하는 사람 체크
        }
    }

    int ans = 0;
    // 파티에 진실 아는 사람 있는지 확인
    for (int i = 0; i < m; i++) {
        bool flag = false;
        for (int j: party[i]) {
            if (know[j]) {
                flag = true;
                break;
            }
        }
        if (!flag) ans++;
    }
    cout << ans;

    return 0;
}