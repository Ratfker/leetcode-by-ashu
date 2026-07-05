class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int m = primes.size();
        vector<long long> dp(n + 1);
        vector<int> idx(m, 0);
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            long long mn = LLONG_MAX;
            for (int j = 0; j < m; j++)
                mn = min(mn, dp[idx[j]] * primes[j]);
            dp[i] = mn;
            for (int j = 0; j < m; j++)
                if (dp[idx[j]] * primes[j] == mn)
                    idx[j]++;
        }
        return dp[n - 1];
    }
};