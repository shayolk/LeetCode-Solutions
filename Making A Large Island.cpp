class Solution {
    int n;
    
    const int dr[4] = {-1,  0,  0, +1};
    const int dc[4] = { 0, -1, +1,  0};
    
    bool ok(int i, int j) {
        return i>=0 && i<n && j>=0 && j<n;
    }
    
    int dfs(int i, int j, int id, vector<vector<int>>& a, vector<vector<bool>>& vis, vector<pair<int,int>>& ind) {
        // cout<<i<<" "<<j<<"\n";
        vis[i][j]=true;
        a[i][j]=id;
        ind.push_back({i, j});
        int here=1;
        for(int k=0; k<4; ++k) {
            int r=i+dr[k], c=j+dc[k];
            if(ok(r, c) && a[r][c] && !vis[r][c]) {
                here+=dfs(r, c, id, a, vis, ind);
            }
        }
        return here;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        n=grid.size();
        vector<vector<bool>> vis(n, vector<bool> (n));
        vector<vector<int>> dp(n, vector<int> (n));
        int ans=0, id=1;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                if(grid[i][j]  && !vis[i][j]) {
                    vector<pair<int,int>> ind;
                    int now=dfs(i, j, id, grid, vis, ind);
                    // cout<<i<<" "<<j<<" "<<now<<"\n";
                    ans=max(ans, now);
                    for(auto p: ind) {
                        dp[p.first][p.second]=now;
                    }
                    ++id;
                }
            }
        }
        // for(int i=0; i<n; ++i) {
        //     for(int j=0; j<n; ++j) {
        //         cout<<grid[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                if(!grid[i][j]) {
                    int here=1;
                    set<int> done;
                    for(int k=0; k<4; ++k) {
                        int r=i+dr[k], c=j+dc[k];
                        if(ok(r, c) && grid[r][c] && !done.count(grid[r][c])) {
                            here+=dp[r][c];
                            done.insert(grid[r][c]);
                        }
                    }
                    ans=max(ans, here);
                }
            }
        }
        return ans;
    }
};
