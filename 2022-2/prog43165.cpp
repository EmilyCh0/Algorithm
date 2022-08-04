#include <string>
#include <vector>

using namespace std;

int n, t;
int cnt = 0;
vector<int> nums;

void dfs(int res, int idx) {
    if (idx == n) {
        if (res == t)
            cnt++;
        return;
    }
    dfs(res + nums[idx], idx + 1);
    dfs(res - nums[idx], idx + 1);
}

int solution(vector<int> numbers, int target) {

    n = numbers.size();
    t = target;
    nums.assign(numbers.begin(), numbers.end());
    dfs(nums[0], 1);
    dfs(0-nums[0], 1);

    return cnt;
}