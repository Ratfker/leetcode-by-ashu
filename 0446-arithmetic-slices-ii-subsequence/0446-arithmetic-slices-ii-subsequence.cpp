class Solution {
public:
    int numberOfArithmeticSlices(std::vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;

        int total_count = 0;
        std::vector<std::unordered_map<long long, int>> dp(n);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                
                long long diff = (long long)nums[i] - nums[j];
                
                
                int count_at_j = 0;
                if (dp[j].count(diff)) {
                    count_at_j = dp[j][diff];
                }

                
                total_count += count_at_j;

                
                dp[i][diff] += count_at_j + 1;
            }
        }

        return total_count;
    }
};