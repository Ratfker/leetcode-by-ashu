class Solution {
public:
    bool rows[9][9]{}, cols[9][9]{}, boxes[9][9]{};

    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (board[i][j] != '.') {
                    int d = board[i][j] - '1';
                    rows[i][d] = cols[j][d] = boxes[(i/3)*3+j/3][d] = true;
                }
        solve(board, 0, 0);
    }

    bool solve(vector<vector<char>>& board, int i, int j) {
        if (i == 9) return true;
        int ni = j == 8 ? i + 1 : i;
        int nj = j == 8 ? 0 : j + 1;
        if (board[i][j] != '.') return solve(board, ni, nj);
        int box = (i/3)*3+j/3;
        for (int d = 0; d < 9; d++) {
            if (rows[i][d] || cols[j][d] || boxes[box][d]) continue;
            rows[i][d] = cols[j][d] = boxes[box][d] = true;
            board[i][j] = '1' + d;
            if (solve(board, ni, nj)) return true;
            rows[i][d] = cols[j][d] = boxes[box][d] = false;
            board[i][j] = '.';
        }
        return false;
    }
};