class Solution {
    int n, m;
    vector<vector<bool>> vis;
    vector<vector<int>> ans;
    
    bool ok(int r, int c) {
        return r>=0 && r<n && c>=0 && c<m;
    }
    
    vector<int> dfs(int r, int c, vector<vector<int>>& land) {
        // cout<<r<<" "<<c<<"\n";
        vis[r][c]=true;
        vector<int> ret={r, c};
        if(ok(r+1, c) && !vis[r+1][c] && land[r+1][c]) {
            vector<int> his=dfs(r+1, c, land);
            ret[0]=max(ret[0], his[0]);
            ret[1]=max(ret[1], his[1]);
        }
        if(ok(r, c+1) && !vis[r][c+1] && land[r][c+1]) {
            vector<int> his=dfs(r, c+1, land);
            ret[0]=max(ret[0], his[0]);
            ret[1]=max(ret[1], his[1]);
        }
        return ret;
    }
    
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        n=land.size();
        m=land[0].size();
        vis.resize(n, vector<bool> (m, false));
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(land[i][j] && !vis[i][j]) {
                    vector<int> his=dfs(i, j, land);
                    ans.push_back({i, j, his[0], his[1]});
                }
            }
        }
        return ans;
    }
};
