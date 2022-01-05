#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> vec;
vector<bool> isUsed;
int maxnum=0;

void backtrack(int cnt, int sum) {
    if (cnt == 0) {
        maxnum = max(maxnum, sum);
        return;
    }
    for (int i = 1; i < n - 1; i++) {
        if (isUsed[i]) {
            continue;
        }
        isUsed[i] = true;
        int left = -1, right = -1;
        for (int j = i - 1; j >= 0; j--) {
            if (isUsed[j]) {
                continue;
            } else {
                left = vec[j];
                break;
            }
        }
        for (int j = i + 1; j < n; j++) {
            if (isUsed[j]) {
                continue;
            } else {
                right = vec[j];
                break;
            }
        }
        sum += (left * right);
        backtrack(cnt - 1, sum);
        isUsed[i] = false;
        sum -= (left * right);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vec.resize(n);
    isUsed.resize(n, false);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    int cnt = n - 2;
    int sum = 0;
    backtrack(cnt, sum);
    cout << maxnum;

    return 0;
}