class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        int total = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (total % 4 != 0) return false;
        int side = total / 4;

        vector<int> dp(1 << n, -1);
        dp[0] = 0;

        for (int mask = 0; mask < (1 << n); mask++) {
            if (dp[mask] == -1) continue;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) continue;
                int next = dp[mask] + matchsticks[i];
                if (next <= side) {
                    dp[mask | (1 << i)] = next % side;
                }
            }
        }

        return dp[(1 << n) - 1] == 0;
    }
};