#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> vec(n + 1, vector<int>(n + 1, 987654321));

    for (int i = 1; i <= n; i++) {
        vec[i][i] = 1;
    }

    int a, b;
    while (true) {
        cin >> a >> b;
        if (a == -1) {
            break;
        }
        vec[a][b] = vec[b][a] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (vec[j][k] > vec[j][i] + vec[k][i]) {
                    vec[j][k] = vec[j][i] + vec[k][i];
                }
            }
        }
    }
    vector<int> score(n, 0);
    int minS = 987654321;
    for (int i = 1; i <= n; i++) {
        int maxScore = 0;
        for (int j = 1; j <= n; j++) {
            maxScore = max(maxScore, vec[i][j]);
        }
        score[i - 1] = maxScore;
        minS = min(maxScore, minS);
    }

    int cnt = 0;
    vector<int> mem;

    for (int i = 0; i < n; i++) {
        if (score[i] == minS) {
            cnt++;
            mem.push_back(i + 1);
        }
    }
    cout << minS << " " << cnt << "\n";
    for (int i = 0; i < mem.size(); i++) {
        cout << mem[i] << " ";
    }

    return 0;
}
