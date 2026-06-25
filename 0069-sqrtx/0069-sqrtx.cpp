class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;

        long long lo = 1, hi = x / 2, ans = 1;

        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;

            if (mid * mid == x) return mid;
            else if (mid * mid < x) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};