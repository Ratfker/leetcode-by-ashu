class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> digit, pos;
    vector<long long> pref, hashVal, pow10;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                digit.push_back(s[i] - '0');
                pos.push_back(i);
            }
        }

        int m = digit.size();

        pref.assign(m + 1, 0);
        hashVal.assign(m + 1, 0);
        pow10.assign(m + 1, 1);

        for (int i = 0; i < m; i++) {
            pref[i + 1] = pref[i] + digit[i];
            hashVal[i + 1] = (hashVal[i] * 10 + digit[i]) % MOD;
            pow10[i + 1] = (pow10[i] * 10) % MOD;
        }

        vector<int> ans;

        for (auto &q : queries) {

            int l = q[0];
            int r = q[1];

            int L = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
            int R = upper_bound(pos.begin(), pos.end(), r) - pos.begin() - 1;

            if (L > R) {
                ans.push_back(0);
                continue;
            }

            long long sum = pref[R + 1] - pref[L];

            int len = R - L + 1;

            long long num =
                (hashVal[R + 1] -
                 hashVal[L] * pow10[len] % MOD +
                 MOD) % MOD;

            ans.push_back(num * sum % MOD);
        }

        return ans;
    }
};