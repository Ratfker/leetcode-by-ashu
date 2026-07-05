class Solution {
public:
    string smallestGoodBase(string n) {
        long long num = stoll(n);
        int maxM = (int)(log2(num)) + 1;

        for (int m = maxM; m >= 3; m--) {
            long long k = (long long)pow((double)num, 1.0 / (m - 1));
            for (long long base = max(2LL, k); base <= k + 1; base++) {
                long long sum = 0, cur = 1;
                bool valid = true;
                for (int i = 0; i < m; i++) {
                    sum += cur;
                    if (sum > num) { valid = false; break; }
                    if (i < m - 1) {
                        if (cur > num / base) { valid = false; break; }
                        cur *= base;
                    }
                }
                if (valid && sum == num)
                    return to_string(base);
            }
        }

        return to_string(num - 1);
    }
};