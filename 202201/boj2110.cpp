#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, c;
    cin >> n >> c;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());

    int left = 1;
    int right = vec[n - 1] - vec[0];
    int ans = 0;

    while (left <= right) {
        int gap = (left + right) / 2;
        int cnt = 1;
        int bef = vec[0];
        for (int i = 1; i < n; i++) {
            if (vec[i] - bef >= gap) {
                cnt++;
                bef = vec[i];
            }
        }
        if (cnt >= c) {
            ans = gap;
            left = gap + 1;
        } else {
            right = gap - 1;
        }
    }

    cout << ans;

    return 0;
}
