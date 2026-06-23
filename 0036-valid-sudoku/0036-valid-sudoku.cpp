class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][9] = {}, cols[9][9] = {}, boxes[9][9] = {};
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int d = board[i][j] - '1';
                int box = (i / 3) * 3 + j / 3;
                if (rows[i][d]++ || cols[j][d]++ || boxes[box][d]++)
                    return false;
            }
        }
        return true;
    }
};