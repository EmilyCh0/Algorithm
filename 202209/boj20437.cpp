// Created by Emily Cho on 2022/09/08.
// 백준 20437 문자열 게임 2 (골5)

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        int k;
        cin >> k;
        vector<vector<int>> alpha(26);
        for (int i = 0; i < str.size(); i++) {
            alpha[str[i] - 'a'].push_back(i);
        }
        int mx = 0;
        int mn = 10001;
        bool flag = true;
        for (int i = 0; i < 26; i++) {
            if (alpha[i].size() >= k) {
                flag = false;
                for (int j = k - 1; j < alpha[i].size(); j++) {
                    mx = max(mx, alpha[i][j] - alpha[i][j - k + 1] + 1);
                    mn = min(mn, alpha[i][j] - alpha[i][j - k + 1] + 1);
                }
            }
        }
        if (flag) cout << -1 << '\n';
        else {
            cout << mn << ' ' << mx << '\n';
        }

    }

    return 0;
}

