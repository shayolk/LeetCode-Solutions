class Solution {
    int n;
    vector<int> par, rank;
    
    void init() {
        par.clear();
        par.resize(n);
        iota(par.begin(), par.end(), 0);
        rank.clear();
        rank.resize(n);
    }
    
    int Find(int x) {
        if(par[x]==x) {
            return x;
        }
        return par[x]=Find(par[x]);
    }
    
    bool Union(int x, int y) {
        int px=Find(x), py=Find(y);
        if(px==py) return true;
        if(rank[py]<rank[px]) swap(px, py);
        par[px]=py;
        if(rank[px]==rank[py]) ++rank[py];
        return false;
    }
    
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        n=edges.size();
        init();
        for(int i=0; i<n; ++i) {
            if(Union(edges[i][0]-1, edges[i][1]-1)) {
                return edges[i];
            }
        }
        return {-1, -1};
    }
};
