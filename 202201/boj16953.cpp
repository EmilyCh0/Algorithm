#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    int cnt = 1;
    while (a != b) {
        if (b == 0 || (b % 2 == 1 && b % 10 > 1)) {
            cout << -1;
            exit(0);
        }
        if (b % 2 == 1) {
            b /= 10;
            cnt++;
        } else {
            b /= 2;
            cnt++;
        }
    }
    cout << cnt;

    return 0;
}