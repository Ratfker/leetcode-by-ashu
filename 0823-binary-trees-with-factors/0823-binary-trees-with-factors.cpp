class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        sort(arr.begin(), arr.end());
        unordered_map<int, long long> dp;

        for (int i = 0; i < arr.size(); i++) {
            dp[arr[i]] = 1;
            for (int j = 0; j < i; j++) {
                if (arr[i] % arr[j] == 0 && dp.count(arr[i] / arr[j]))
                    dp[arr[i]] = (dp[arr[i]] + dp[arr[j]] * dp[arr[i] / arr[j]]) % MOD;
            }
        }

        long long ans = 0;
        for (auto& [k, v] : dp)
            ans = (ans + v) % MOD;
        return ans;
    }
};