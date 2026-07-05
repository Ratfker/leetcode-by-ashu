class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) return 9;

        long long upper = (long long)pow(10, n) - 1;
        long long lower = (long long)pow(10, n - 1);

        for (long long half = upper; half >= lower; half--) {
            string s = to_string(half);
            string rev = s;
            reverse(rev.begin(), rev.end());
            long long palindrome = stoll(s + rev);

            for (long long i = upper; i * i >= palindrome; i--) {
                if (palindrome % i == 0 && palindrome / i >= lower) {
                    return (int)(palindrome % 1337);
                }
            }
        }

        return -1;
    }
};