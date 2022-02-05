#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    vector<int> dp(n);
    dp[0] = vec[0];

    for (int i = 1; i < n; i++) {
        int tmp = 0;
        for (int j = 0; j < i; j++) {
            if (vec[j] < vec[i]) {
                tmp = max(tmp, dp[j]);
            }
        }
        dp[i] = tmp + vec[i];
    }
    sort(dp.begin(), dp.end());
    cout << dp[n - 1];

    return 0;
}