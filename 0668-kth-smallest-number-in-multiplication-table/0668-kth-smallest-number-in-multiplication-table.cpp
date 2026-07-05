class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int lo = 1, hi = m * n;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int count = 0;
            for (int i = 1; i <= m; i++) {
                count += min(mid / i, n);
            }
            if (count < k) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
};