#include "iostream"
#include "vector"
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<vector<vector<int>>> dp(101, vector<vector<int>>(101, vector<int>(2)));
    dp[1][0][0] = 1;
    dp[1][0][1] = 1;
    for (int i = 2; i < 101; i++) {
        for (int j = 0; j < i; j++) {
            dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
            if (j == 0) {
                dp[i][j][1] = dp[i - 1][j][0];
            } else {
                dp[i][j][1] = dp[i - 1][j - 1][1] + dp[i - 1][j][0];
            }

        }
    }

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        cout << dp[n][k][0] + dp[n][k][1] << '\n';
    }

    return 0;
}