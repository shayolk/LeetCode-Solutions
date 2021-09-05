class Solution {
    vector<int> count, sum;
    vector<vector<int>> adj;
    
    void dfs(int now, int par) {
        for(int neb: adj[now]) {
            if(neb!=par) {
                dfs(neb, now);
                count[now]+=count[neb];
                sum[now]+=sum[neb]+count[neb];
            }
        }
    }
    
    void compute(int now, int par, int n) {
        for(int neb: adj[now]) {
            if(neb!=par) {
                sum[neb]=sum[now]+n-2*count[neb];
                compute(neb, now, n);
            }
        }
    }
    
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        count.resize(n, 1);
        sum.resize(n);
        adj.resize(n);
        for(auto edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        dfs(0, -1);
        compute(0, -1, n);
        return sum;
    }
};
