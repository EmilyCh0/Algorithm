#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<vector<int>> vec;
set<string> ss;
int di[] = {0,0,1,-1};
int dj[] = {1,-1,0,0};

void func(string str, int i, int j) {
    if (str.size() == 7) {
        ss.insert(str);
        return;
    }
    for (int k = 0; k < 4; k++) {
        int ni = i + di[k];
        int nj = j + dj[k];
        if (ni < 0 || nj < 0 || ni >= 4 || nj >= 4) continue;
        func(str + to_string(vec[ni][nj]), ni, nj);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        vec.assign(4, vector<int>(4));
        ss.clear();
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> vec[i][j];
            }
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                func(to_string(vec[i][j]), i, j);
            }
        }
        cout << "#" << tc << " " << ss.size() << "\n";
    }

    return 0;
}