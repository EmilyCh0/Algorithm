class Solution {
public:
    vector <string> summaryRanges(vector<int> &nums) {
        int s = 0, e = 0;
        nums.push_back(-1);
        vector <string> ans;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] != 2147483647 && nums[i] == nums[i - 1] + 1) {
                e = i;
            } else {
                if (s == e) {
                    ans.push_back(to_string(nums[s]));
                } else {
                    string str = to_string(nums[s]) + "->" + to_string(nums[e]);
                    ans.push_back(str);
                }
                s = e = i;
            }
        }
        return ans;
    }
};