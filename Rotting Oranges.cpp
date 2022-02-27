class Solution {
    int n, m;
    
    int dr[4]={1, -1, 0, 0};
    int dc[4]={0, 0, 1, -1};
    
    bool safe(int r, int c) {
        return r>=0 && r<n && c>=0 && c<m;
    }
    
public:
    int orangesRotting(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m));
        queue<pair<int,int>> q;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(!vis[i][j] && grid[i][j]==2) {
                    vis[i][j]=true;
                    q.push({i, j});
                }
            }
        }
        q.push({-1, -1});
        int time=0;
        while(!q.empty()) {
            pair<int,int> now=q.front();
            q.pop();
            if(now.first==-1) {
                if(q.empty()) break;
                ++time;
                q.push({-1, -1});
                continue;
            }
            for(int d=0; d<4; ++d) {
                int r=now.first+dr[d], c=now.second+dc[d];
                if(safe(r, c) && !vis[r][c] && grid[r][c]==1) {
                    grid[r][c]=2;
                    vis[r][c]=true;
                    q.push({r, c});
                }
            }
        }
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(grid[i][j]==1) {
                    return -1;
                }
            }
        }
        return time;
    }
};
