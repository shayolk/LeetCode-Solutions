class Solution {
    const int dr[4]={0, 0, -1, 1};
    const int dc[4]={-1, 1, 0, 0};
    
    int n,m;
    
    bool safe(int r, int c, vector<vector<int>>& grid) {
        return r>=0 && r<n && c>=0 && c<m && grid[r][c]==1;
    }
    
    int dfs(int r, int c, vector<vector<int>>& grid) {
        grid[r][c]=-1;
        int here=1;
        for(int d=0; d<4; ++d) {
            int rr=r+dr[d], cc=c+dc[d];
            if(!safe(rr, cc, grid)) continue;
            here+=dfs(rr, cc, grid);
        }
        return here;
    }
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int ans=0;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(grid[i][j]==1) {
                    ans=max(ans, dfs(i, j, grid));
                }
            }
        }
        return ans;
    }
};
