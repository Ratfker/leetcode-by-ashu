class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> cols, d1, d2;
        vector<string> board(n, string(n, '.'));
        solve(res, board, cols, d1, d2, 0, n);
        return res;
    }

    void solve(vector<vector<string>>& res, vector<string>& board, vector<int>& cols, vector<int>& d1, vector<int>& d2, int row, int n) {
        if (row == n) { res.push_back(board); return; }
        for (int col = 0; col < n; col++) {
            if (count(cols.begin(),cols.end(),col) || count(d1.begin(),d1.end(),row-col) || count(d2.begin(),d2.end(),row+col)) continue;
            board[row][col] = 'Q';
            cols.push_back(col); d1.push_back(row-col); d2.push_back(row+col);
            solve(res, board, cols, d1, d2, row+1, n);
            board[row][col] = '.';
            cols.pop_back(); d1.pop_back(); d2.pop_back();
        }
    }
};