#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, h, tmp;
    cin >> n >> h;

    vector<int> low(h + 1, 0);
    vector<int> high(h + 1, 0);

    for (int i = 0; i < n / 2; i++) {
        cin >> tmp;
        low[tmp]++;
        cin >> tmp;
        high[tmp]++;
    }

    vector<int> cumSumL(h + 1, 0);
    vector<int> cumSumH(h + 1, 0);

    int tmp1 = 0, tmp2 = 0;
    for (int i = h; i > 0; i--) {
        tmp1 += low[i];
        tmp2 += high[i];
        cumSumL[i] = tmp1;
        cumSumH[i] = tmp2;
    }
    vector<int> cumSum(h + 1, 0);
    for (int i = 1; i <= h; i++) {
        cumSum[i] = cumSumL[i] + cumSumH[h - i + 1];
    }
    sort(cumSum.begin(), cumSum.end());
    int ans = cumSum[1];
    int cnt = 0;
    for (int i = 1; i <= cumSum.size(); i++) {
        if (cumSum[i] == ans) {
            cnt++;
        } else {
            break;
        }
    }
    cout << ans << " " << cnt;

    return 0;
}

