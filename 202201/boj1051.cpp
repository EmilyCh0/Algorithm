#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> vec(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++) {
            vec[i][j] = str[j] - '0';
        }
    }

    int area = 1;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            for (int k = 1; k < min(n - i, m - j); k++) {
                int tmp = vec[i][j];
                if (vec[i + k][j] == tmp && vec[i][j + k] == tmp && vec[i + k][j + k] == tmp) {
                    area = max(area, (k + 1) * (k + 1));
                }
            }
        }
    }
    cout << area;

    return 0;
}
