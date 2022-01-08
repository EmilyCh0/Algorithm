#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> fib(46);
        fib[0] = 0;
        fib[1] = 1;
        for (int j = 2; j < 46; j++) {
            fib[j] = fib[j - 1] + fib[j - 2];
        }
        vector<int> ans;
        for (int j = 45; j > 0; j--) {
            if (fib[j] <= n) {
                n -= fib[j];
                ans.push_back(fib[j]);
            }
        }
        for (int j = ans.size() - 1; j >= 0; j--) {
            cout << ans[j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
