#include <iostream>
#include <vector>
using namespace std;

int n;
int ans = 0;
vector<vector<int>> map(17,vector<int>(17));

void Pipe(int i, int j, int dir) {
    if (i == n && j == n) {
        ans++;
        return;
    }
    if (dir == 0) {
        if (j < n) {
            if (map[i][j + 1] != 1)
                Pipe(i, j + 1, 0);
        }
        if (j < n && i < n) {
            if (map[i][j + 1] != 1 && map[i + 1][j] != 1 && map[i + 1][j + 1] != 1) {
                Pipe(i + 1, j + 1, 1);
            }
        }
    } else if (dir == 1) {
        if (j < n) {
            if (map[i][j + 1] != 1) {
                Pipe(i, j + 1, 0);
            }
        }
        if (j < n && i < n) {
            if (map[i][j + 1] != 1 && map[i + 1][j] != 1 && map[i + 1][j + 1] != 1) {
                Pipe(i + 1, j + 1, 1);
            }
        }
        if (i < n) {
            if (map[i + 1][j] != 1) {
                Pipe(i + 1, j, 2);
            }
        }
    } else {
        if (j < n && i < n) {
            if (map[i][j + 1] != 1 && map[i + 1][j] != 1 && map[i + 1][j + 1] != 1) {
                Pipe(i + 1, j + 1, 1);
            }
        }
        if (i < n) {
            if (map[i + 1][j] != 1) {
                Pipe(i + 1, j, 2);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }

    Pipe(1, 2, 0);

    cout << ans;

    return 0;
}

