#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<string>> calcRes(101, vector<string>(101));

string addStr(string str1, string str2) {
    int sum = 0;
    string res;
    while (true) {
        if (str1.empty() && str2.empty()) {
            if (sum != 0) {
                res.push_back(sum + '0');
            }
            break;
        }
        if (!str1.empty()) {
            sum += str1.back() - '0';
            str1.pop_back();
        }
        if (!str2.empty()) {
            sum += str2.back() - '0';
            str2.pop_back();
        }
        res.push_back(sum % 10 + '0');
        sum /= 10;
    }

    reverse(res.begin(), res.end());
    return res;
}

void comb(int n, int m) {
    calcRes[0][0] = "1";
    calcRes[1][0] = calcRes[1][1] = "1";
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == j || j == 0) {
                calcRes[i][j] = "1";
            } else {
                calcRes[i][j] = addStr(calcRes[i - 1][j - 1], calcRes[i - 1][j]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    if (m > n / 2)
        m = n - m;


    comb(n, m);
    cout << calcRes[n][m];
    return 0;
}