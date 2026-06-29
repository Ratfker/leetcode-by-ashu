class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int curMin = nums[0];
        int curMax = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int tmp = curMax;
            curMax = max({nums[i], curMax * nums[i], curMin * nums[i]});
            curMin = min({nums[i], tmp * nums[i], curMin * nums[i]});
            res = max(res, curMax);
        }

        return res;
    }
};