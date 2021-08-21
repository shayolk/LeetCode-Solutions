class Solution {
    vector<vector<bool>> row, col, box;
    
    bool solve(int r, int c, vector<vector<char>>& b) {
        if(c==9) {
            ++r;
            c=0;
        }
        if(r==9) return true;
        if(b[r][c]!='.') return solve(r, c+1, b);
        for(int i=1; i<=9; ++i) {
            if(row[r][i] || col[c][i] || box[(r/3)*3+c/3][i]) continue;
            b[r][c]='0'+i;
            row[r][i]=col[c][i]=box[(r/3)*3+c/3][i]=true;
            if(solve(r, c+1, b)) return true;
            b[r][c]='.';
            row[r][i]=col[c][i]=box[(r/3)*3+c/3][i]=false;
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        row.resize(9, vector<bool> (10));
        col.resize(9, vector<bool> (10));
        box.resize(9, vector<bool> (10));
        for(int i=0; i<9; ++i) {
            for(int j=0; j<9; ++j) {
                if(board[i][j]!='.') {
                    row[i][board[i][j]-'0']=col[j][board[i][j]-'0']=box[(i/3)*3+j/3][board[i][j]-'0']=true;
                }
            }
        }
        solve(0, 0, board);
    }
};
