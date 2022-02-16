#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    map<string, int> map;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        map[str] = 1;
    }
    for (int i = 0; i < m; i++) {
        string str;
        cin >> str;
        if (map.find(str) == map.end()) {
            continue;
        } else {
            cnt++;
        }
    }
    cout << cnt;

    return 0;
}
