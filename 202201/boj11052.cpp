#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> vec(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> vec[i];
    }
    vector<int> dp(n + 1);
    dp[1] = vec[1];
    for (int i = 2; i <= n; i++) {
        int maxnum = vec[i];
        for (int j = 1; j <= i / 2; j++) {
            int left = j;
            int right = i - j;
            maxnum = max(maxnum, dp[left] + dp[right]);
        }
        dp[i] = maxnum;
    }
    cout << dp[n];
    return 0;
}

