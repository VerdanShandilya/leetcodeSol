class Solution {
public:
    bool helper(vector<vector<char>>& board, char input, int row, int col) {
        bool a = true;
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == input) {
                a = false;
                break;
            }
        } 
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == input) {
                a = false;
                break;
            }
        }
        for (int i = 0; i < 9; i++) {
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == input) {
                a = false;
                break;
            }
        }
        return a;
    }
    bool shelper(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (helper(board, c, i, j)) {
                            board[i][j] = c;
                            if (shelper(board)) {
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        shelper(board);
    }
};
