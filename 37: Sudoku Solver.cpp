class Solution {
    vector<vector<bool>> row, col, box;

    int index(int r, int c) {
        return (r / 3) * 3 + c / 3;
    }

    bool solve(int r, int c, vector<vector<char>>& board) {
        if(c == 9) {
            ++r;
            c = 0;
        }
        if(r == 9) {
            return true;
        }
        if(board[r][c] != '.') {
            return solve(r, c + 1, board);
        }
        for(int i=1; i<=9; ++i) {
            if(row[r][i] || col[c][i] || box[index(r, c)][i]) {
                continue;
            }
            row[r][i] = true;
            col[c][i] = true;
            box[index(r, c)][i] = true;
            board[r][c] = ('0' + i);
            if(solve(r, c + 1, board)) {
                return true;
            }
            board[r][c] = '.';
            box[index(r, c)][i] = false;
            col[c][i] = false;
            row[r][i] = false;
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        row.resize(9, vector<bool> (10, false));
        col.resize(9, vector<bool> (10, false));
        box.resize(9, vector<bool> (10, false));
        for(int i=0; i<9; ++i) {
            for(int j=0; j<9; ++j) {
                if(board[i][j] == '.') {
                    continue;
                }
                int val = board[i][j] - '0';
                row[i][val] = true;
                col[j][val] = true;
                box[index(i, j)][val] = true;
            }
        }
        solve(0, 0, board);
    }
};
