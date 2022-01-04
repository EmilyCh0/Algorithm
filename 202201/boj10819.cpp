#include "iostream"
#include "vector"
using namespace std;
int n;
vector<int> nums;
vector<bool> isUsed;
vector<int> vec;
int maxnum = 0;

int calc() {
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += abs(vec[i] - vec[i + 1]);
    }
    return sum;
}

void backtrack() {
    if (vec.size() == n) {
        maxnum = max(calc(), maxnum);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (isUsed[i]) {
            continue;
        }
        isUsed[i] = true;
        vec.push_back(nums[i]);
        backtrack();
        isUsed[i] = false;
        vec.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    nums.resize(n);
    isUsed.resize(n, false);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    backtrack();

    cout << maxnum;
    return 0;
}
