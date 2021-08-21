class Solution {
    const int M=1e9+7;
    vector<vector<pair<int, int>>> adj;
    vector<long long> dist, dp;
    
    long long dfs(int now, int n, long long cost) {
        if(cost!=dist[now]) return 0;
        if(now==n) return 1;
        if(dp[now]!=-1) return dp[now];
        long long here=0;
        for(auto neb: adj[now]) {
            here=(here+dfs(neb.first, n, cost+neb.second))%M;
        }
        return dp[now]=here;
    }
    
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        adj.resize(n);
        for(auto v: roads) {
            adj[v[0]].push_back({v[1], v[2]});
            adj[v[1]].push_back({v[0], v[2]});
        }
        dist.resize(n, 1e18+5);
        dist[0]=0;
        vector<bool> vis(n);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> p;
        p.push({0, 0});
        while(!p.empty()) {
            pair<long long,int> pr=p.top();
            p.pop();
            int now=pr.second;
            long long val=pr.first;
            if(dist[now]<val) continue;
            vis[now]=true;
            for(auto neb: adj[now]) {
                if(!vis[neb.first] && dist[now]+neb.second<dist[neb.first]) {
                    dist[neb.first]=dist[now]+neb.second;
                    p.push({dist[neb.first], neb.first});
                }
            }
        }
        dp.resize(n+1, -1);
        return dfs(0, n-1, 0);
    }
};
