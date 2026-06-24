class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        int cols = 0, d1 = 0, d2 = 0;
        solve(res, cols, d1, d2, 0, n);
        return res;
    }

    void solve(int& res, int cols, int d1, int d2, int row, int n) {
        if (row == n) { res++; return; }
        int avail = ((1 << n) - 1) & ~(cols | d1 | d2);
        while (avail) {
            int bit = avail & (-avail);
            avail &= avail - 1;
            solve(res, cols | bit, (d1 | bit) << 1, (d2 | bit) >> 1, row + 1, n);
        }
    }
};