class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        
        for (int len = 2; len <= n; len++) {
            for (int i = 1; i + len - 1 <= n; i++) {
                int j = i + len - 1;
                int minCost = INT_MAX;
                for (int x = i; x <= j; x++) {
                    int left = (x > i) ? dp[i][x - 1] : 0;
                    int right = (x < j) ? dp[x + 1][j] : 0;
                    int cost = x + max(left, right);
                    minCost = min(minCost, cost);
                }
                dp[i][j] = minCost;
            }
        }
        
        return dp[1][n];
    }
};