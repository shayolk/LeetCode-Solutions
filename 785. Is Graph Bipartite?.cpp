class Solution {
    int n;
    vector<int> group;

    bool dfs(int now, int col, vector<vector<int>>& graph) {
        group[now] = col;
        for(int neb: graph[now]) {
            if(group[neb] == col) {
                return false;
            }
            if(group[neb] == (1 - col)) {
                continue;
            }
            if(!dfs(neb, 1 - col, graph)) {
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        n = graph.size();
        group.resize(n, -1);
        for(int i = 0; i < n; ++i) {
            if(group[i] == -1) {
                if(!dfs(i, 0, graph)) {
                    return false;
                }
            }
        }
        return true;
    }
};
