#include "iostream"
#include "vector"
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> coin(n, 0);
    for (int i = n - 1; i >= 0; i--) {
        cin >> coin[i];
    }
    int sIdx;
    for (int i = 0; i < n; i++) {
        if (coin[i] <= k) {
            sIdx = i;
            break;
        }
    }
    int cnt = 0;
    int sum = 0;
    int ans = k;
    while (true) {
        if (sum == ans) {
            break;
        }
        sum += (k / coin[sIdx]) * coin[sIdx];
        cnt += k / coin[sIdx];
        k %= coin[sIdx];
        sIdx++;
    }
    cout << cnt;

    return 0;
}


