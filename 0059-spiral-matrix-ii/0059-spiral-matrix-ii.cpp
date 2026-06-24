class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int top = 0, bot = n-1, left = 0, right = n-1, num = 1;
        while (top <= bot && left <= right) {
            for (int i = left; i <= right; i++) res[top][i] = num++; top++;
            for (int i = top; i <= bot; i++) res[i][right] = num++; right--;
            if (top <= bot) { for (int i = right; i >= left; i--) res[bot][i] = num++; bot--; }
            if (left <= right) { for (int i = bot; i >= top; i--) res[i][left] = num++; left++; }
        }
        return res;
    }
};