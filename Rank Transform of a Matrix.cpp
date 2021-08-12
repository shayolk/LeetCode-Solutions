class Solution {
    struct UF {
        map<int,int> par;

        int Find(int u) {
            if(!par[u]) {
                par[u]=u;
            }
            if(par[u]!=u) {
                par[u]=Find(par[u]);
            }
            return par[u];
        }

        void Union(int u, int v) {
            int pu=Find(u), pv=Find(v);
            if(pu!=pv) {
                par[pu]=pv;
            }
        }

        map<int,vector<int>> Get() {
            map<int,vector<int>> m;
            for(auto i: par) {
                m[Find(i.first)].push_back(i.first);
            }
            return m;
        }
    };
    
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();
        vector<vector<int>> ans(n, vector<int> (m));
        map<int,vector<pair<int,int>>> mp;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                mp[matrix[i][j]].push_back({i, j});
            }
        }
        vector<int> rank(n+m);
        for(auto i: mp) {
            int v=i.first;
            UF uf;
            for(auto p: i.second) {
                int r=p.first, c=p.second;
                uf.Union(r, c+n);
            }
            map<int,vector<int>> g=uf.Get();
            for(auto i: g) {
                int here=0;
                for(auto j: i.second) {
                    here=max(here, rank[j]+1);
                }
                for(auto j: i.second) {
                    rank[j]=here;
                }
            }
            for(auto p: i.second) {
                int r=p.first, c=p.second;
                ans[r][c]=rank[r];
            }
        }
        return ans;
    }
};
