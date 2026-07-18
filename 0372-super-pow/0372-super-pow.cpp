class Solution {
public:
    const int MOD = 1337;
    
    int powmod(int a, int k) {
        a %= MOD;
        int result = 1;
        for (int i = 0; i < k; i++) {
            result = (result * a) % MOD;
        }
        return result;
    }
    
    int superPow(int a, vector<int>& b) {
        int result = 1;
        for (int digit : b) {
            result = powmod(result, 10) * powmod(a, digit) % MOD;
        }
        return result;
    }
};