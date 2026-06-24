class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> digits;
        int fact = 1;
        for (int i = 1; i <= n; i++) { digits.push_back(i); fact *= i; }
        k--;
        string res;
        for (int i = n; i >= 1; i--) {
            fact /= i;
            res += to_string(digits[k / fact]);
            digits.erase(digits.begin() + k / fact);
            k %= fact;
        }
        return res;
    }
};