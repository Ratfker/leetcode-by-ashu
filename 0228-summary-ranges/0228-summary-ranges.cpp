class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n = nums.size(), i = 0;
        while (i < n) {
            int j = i;
            while (j + 1 < n && nums[j + 1] == nums[j] + 1) j++;
            if (i == j)
                res.push_back(to_string(nums[i]));
            else
                res.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));
            i = j + 1;
        }
        return res;
    }
};