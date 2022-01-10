#include <iostream>
#include <vector>

using namespace std;
int n;
vector<int> vec(15);
int ans = 0;
bool check(int lv) {
    for (int i = 0; i < lv; i++) {
        if (vec[i] == vec[lv] || abs(vec[lv] - vec[i]) == abs(lv - i)) {
            return false;
        }
    }
    return true;
}
void nqueen(int col) {
    if (col == n) {
        ans++;
    }
    for (int i = 0; i < n; i++) {
        vec[col] = i;
        if (check(col)) {
            nqueen(col + 1);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    nqueen(0);
    cout << ans;

    return 0;
}