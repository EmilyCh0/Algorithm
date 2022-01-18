#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> vec(n);
        for (int j = 0; j < n; j++) {
            cin >> vec[j];
        }
        int money;
        cin >> money;
        vector<int> dp(100001, 0);
        dp[0] = 1;
        for (int j = 0; j < n; j++) {
            for (int k = vec[j]; k <= money; k++) {
                dp[k] += dp[k - vec[j]];
            }
        }
        cout << dp[money] << "\n";
    }

    return 0;
}