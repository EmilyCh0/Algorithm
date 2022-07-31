#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, l;
    cin >> n >> l;
    vector<int> leaks(n);
    for (int i = 0; i < n; i++) {
        cin >> leaks[i];
    }
    sort(leaks.begin(), leaks.end());
    int cnt = 0;
    int tapeStartIdx = 0;
    while (true) {
        int tmp = tapeStartIdx;
        cnt++;
        int tapeEnd = leaks[tapeStartIdx] + l;
        for (int i = tapeStartIdx + 1; i < n; i++) {
            if (leaks[i] >= tapeEnd) {
                tapeStartIdx = i;
                break;
            }
        }
        if (tmp == tapeStartIdx) {
            break;
        }
    }
    cout << cnt;
}