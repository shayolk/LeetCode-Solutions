class Solution {
    int a[4]={0, 1, 0, -1};
    int b[4]={1, 0, -1, 0};
    void trav(int x, int y, int n, int m, vector <vector <char>> grid, vector <vector <int>>& vis) {
        queue <pair <int,int>> q;
        q.push({x,y});
        vis[x][y]=1;
        while(!q.empty()) {
            pair<int,int> p=q.front();
            q.pop();
            for(int i=0; i<4; ++i) {
                if(p.first+a[i]>=0 && p.first+a[i]<n && p.second+b[i]>=0 && p.second+b[i]<m && grid[p.first+a[i]][p.second+b[i]]=='1' && !vis[p.first+a[i]][p.second+b[i]]) {
                    vis[p.first+a[i]][p.second+b[i]]=1;
                    q.push({p.first+a[i], p.second+b[i]});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) {
            return 0;
        }
        int n=grid.size(), m=grid[0].size();
        vector <vector <int>> vis(n, vector<int> (m, 0));
        vector <pair <int,int>> p;
        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j) {
                if(grid[i][j]=='1') {
                    p.push_back({i,j});
                }
            }
        if(p.empty()) {
            return 0;
        }
        int ans=0;
        for(auto i: p) {
            if(!vis[i.first][i.second]) {
                ++ans;
                trav(i.first,i.second,n,m,grid,vis);
            }
        }
        return ans;
    }
};
