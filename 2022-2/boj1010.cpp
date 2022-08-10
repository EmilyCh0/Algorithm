#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> calcResults;

void comb(int n, int m) {
    calcResults[0][0] = calcResults[1][0] = calcResults[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == j || j == 0) calcResults[i][j] = 1;
            else calcResults[i][j] = calcResults[i - 1][j - 1] + calcResults[i - 1][j];
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t, n, m;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> m >> n;
        if (m > n / 2) m = n - m;
        calcResults.assign(n + 1, vector<int>(n + 1, 0));
        comb(n, m);
        cout << calcResults[n][m] << '\n';
    }
    return 0;
}

