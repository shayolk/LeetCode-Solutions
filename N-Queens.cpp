class Solution {
    vector<vector<string>> ans;
    
    bool check(int r, int c, int& n, vector<string>& now) {
        for(int i=r-1; i>=0; --i) {
            if(now[i][c]=='Q') return false;
        }
        for(int i=r-1, j=c-1; i>=0 && j>=0; --i, --j) {
            if(now[i][j]=='Q') return false;
        }
        for(int i=r-1, j=c+1; i>=0 && j<n; --i, ++j) {
            if(now[i][j]=='Q') return false;
        }
        return true;
    }
    
    void find(int i, int& n, vector<string>& now) {
        if(i==n) {
            ans.push_back(now);
            return;
        }
        for(int j=0; j<n; ++j) {
            if(check(i, j, n, now)) {
                now[i][j]='Q';
                find(i+1, n, now);
                now[i][j]='.';
            }
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> now(n, string(n, '.'));
        find(0, n, now);
        return ans;
    }
};
