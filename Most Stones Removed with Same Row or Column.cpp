class Solution {
    map<int,int> xcord, ycord;
    vector<int> par, rank;
    
    int Find(int x) {
        if(par[x]==x) return x;
        return par[x]=Find(par[x]);
    }
    
    int Union(int x, int y) {
        int px=Find(x), py=Find(y);
        if(px==py) return px;
        if(rank[px]<rank[py]) return par[px]=py;
        if(rank[px]>rank[py]) return par[py]=px;
        ++rank[py];
        return par[px]=py;
    }
    
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        par.resize(n);
        rank.resize(n);
        iota(par.begin(), par.end(), 0);
        for(int i=0; i<n; ++i) {
            int x=stones[i][0], y=stones[i][1];
            if(xcord.count(x)) {
                Union(i, xcord[x]);
            }
            if(ycord.count(y)) {
                Union(i, ycord[y]);
            }
            xcord[x]=i;
            ycord[y]=i;
        }
        int cnt=0;
        for(int i=0; i<n; ++i) {
            if(par[i]==i) {
                ++cnt;
            }
        }
        return n-cnt;
    }
};
