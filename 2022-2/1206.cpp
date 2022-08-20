#include<iostream>
#include<vector>

using namespace std;

vector<int> buildings;

int findMaxInRange(int i) {
    int mx = 0;
    mx = max(mx, buildings[i - 2]);
    mx = max(mx, buildings[i - 1]);
    mx = max(mx, buildings[i + 1]);
    mx = max(mx, buildings[i + 2]);
    return mx;
}

int main(int argc, char** argv) {
    int test_case;
    int T = 10;

    for (test_case = 1; test_case <= T; ++test_case) {
        int n;
        cin >> n;
        int ans = 0;
        buildings.assign(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> buildings[i];
        }
        for (int i = 2; i < n - 2; i++) {
            if (buildings[i] == 0) continue;
            int mx = findMaxInRange(i);
            if (mx >= buildings[i]) continue;
            else ans += buildings[i] - mx;
        }
        cout << "#" << test_case << " " << ans << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}