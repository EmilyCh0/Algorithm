#include "iostream"
#include "vector"
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> vec(n);
    vector<int> cnt(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    int ans = 1;
    for (int i = 0; i < n; i++) {
        int maxCnt = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (vec[j] < vec[i]) {
                maxCnt = max(maxCnt, cnt[j]);
            }
        }
        cnt[i] = maxCnt + 1;
        ans = max(ans, cnt[i]);
    }
    cout << n - ans;
    return 0;
}