class Solution {
    const int dr[4]={0, 0, 1, -1};
    const int dc[4]={1, -1, 0, 0};
    
    int n, m;
    vector<vector<int>> dp;
    vector<vector<bool>> vis;
    
    bool safe(int r, int c) {
        return r>=0 && r<n && c>=0 && c<m && !vis[r][c];
    }
    
    int dfs(int r, int c, vector<vector<int>>& matrix) {
        if(dp[r][c]!=-1) return dp[r][c];
        vis[r][c]=true;
        int now=0;
        for(int d=0; d<4; ++d) {
            int rr=r+dr[d], cc=c+dc[d];
            if(!safe(rr, cc)) continue;
            if(matrix[rr][cc]<=matrix[r][c]) continue;
            now=max(now, dfs(rr, cc, matrix));
        }
        vis[r][c]=false;
        return dp[r][c]=1+now;
    }
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();
        dp.resize(n, vector<int> (m, -1));
        vis.resize(n, vector<bool> (m));
        int ans=1;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                ans=max(ans, dfs(i, j, matrix));
            }
        }
        return ans;
    }
};
