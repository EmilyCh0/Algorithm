#include "iostream"
#include "vector"
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<char> vec(n);
    string str;
    cin >> str;
    for (int i = 0; i < n; i++) {
        vec[i] = str[i];
    }
    vector<int> dp(n, 1e9);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        char now = vec[i];
        char next;
        if (now == 'B')
            next = 'O';
        else if (now == 'O')
            next = 'J';
        else
            next = 'B';
        for (int j = i + 1; j < n; j++) {
            if (vec[j] == next) {
                dp[j] = min(dp[j], dp[i] + (j - i) * (j - i));
            }
        }
    }

    if (dp[n - 1] == 1e9) {
        cout << -1;
    } else {
        cout << dp[n - 1];
    }

    return 0;
}

