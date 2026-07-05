class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size(), m = key.size();
        vector<vector<int>> pos(26);
        for (int i = 0; i < n; i++) pos[ring[i] - 'a'].push_back(i);
        
        vector<vector<int>> dp(m + 1, vector<int>(n, 0));
        for (int i = m - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                int best = INT_MAX;
                for (int k : pos[key[i] - 'a']) {
                    int diff = abs(j - k);
                    int dist = min(diff, n - diff);
                    best = min(best, dist + 1 + dp[i+1][k]);
                }
                dp[i][j] = best;
            }
        }
        return dp[0][0];
    }
};