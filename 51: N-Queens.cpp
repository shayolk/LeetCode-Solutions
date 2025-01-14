class Solution {
    int n;
    vector<bool> col, ltr, rtl;
    vector<vector<string>> ans;

    void find(int row, vector<string>& now) {
        if(row == n) {
            ans.push_back(now);
            return;
        }
        for(int i=0; i<n; ++i) {
            if(col[i] || ltr[row-i+n] || rtl[row+i]) {
                continue;
            }
            col[i] = true;
            ltr[row-i+n] = true;
            rtl[row+i] = true;
            now[row][i] = 'Q';
            find(row + 1, now);
            now[row][i] = '.';
            rtl[row+i] = false;
            ltr[row-i+n] = false;
            col[i] = false;
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        vector<string> now(n, string (n, '.'));
        col.resize(n, false);
        ltr.resize(2 * n, false);
        rtl.resize(2 * n, false);
        find(0, now);
        return ans;
    }
};
