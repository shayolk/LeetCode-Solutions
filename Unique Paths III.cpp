class Solution {
    const int dr[4]={0, 0, 1, -1};
    const int dc[4]={1, -1, 0, 0};
    
    int n, m, sr, sc, non, path, ans;
    vector<vector<bool>> vis;
    
    bool safe(int r, int c, vector<vector<int>>& grid) {
        return r>=0 && r<n && c>=0 && c<m && grid[r][c]!=-1 && !vis[r][c];
    }
    
    void find(int r, int c, vector<vector<int>>& grid) {
        if(grid[r][c]==2) {
            if(path==non) ++ans;
            return;
        }
        for(int d=0; d<4; ++d) {
            int rr=r+dr[d], cc=c+dc[d];
            if(!safe(rr, cc, grid)) continue;
            ++path;
            vis[rr][cc]=true;
            find(rr, cc, grid);
            vis[rr][cc]=false;
            --path;
        }
    }
    
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        non=0;
        path=0;
        ans=0;
        vis.resize(n, vector<bool> (m));
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(grid[i][j]==1) {
                    sr=i;
                    sc=j;
                }
                if(grid[i][j]!=-1) {
                    ++non;
                }
            }
        }
        ++path;
        vis[sr][sc]=true;
        find(sr, sc, grid);
        vis[sr][sc]=false;
        --path;
        return ans;
    }
};
