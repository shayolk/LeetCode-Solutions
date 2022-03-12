class Solution {
    int n, m, ans;
    vector<vector<bool>> vis;
    
    const int dr[4]={0, 0, 1, -1};
    const int dc[4]={1, -1, 0, 0};
    
    bool safe(int r, int c) {
        return r>=0 && r<n && c>=0 && c<m;
    }
    
    void dfs(int r, int c, vector<vector<char>>& grid) {
        vis[r][c]=true;
        for(int d=0; d<4; ++d) {
            int rr=r+dr[d], cc=c+dc[d];
            if(safe(rr, cc) && !vis[rr][cc] && grid[rr][cc]=='1') {
                dfs(rr, cc, grid);
            }
        }
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        ans=0;
        vis.resize(n, vector<bool> (m));
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(!vis[i][j] && grid[i][j]=='1') {
                    ++ans;
                    dfs(i, j, grid);
                }
            }
        }
        return ans;
    }
};
