class Solution {
    vector<bool> vis, rec;
    vector<vector<int>> adj;
    
    bool dfs(int now) {
        rec[now]=true;
        vis[now]=true;
        for(int neb: adj[now]) {
            if(!vis[neb] && dfs(neb)) return true;
            if(rec[neb]) return true;
        }
        rec[now]=false;
        return false;
    }
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vis.resize(numCourses);
        rec.resize(numCourses);
        adj.resize(numCourses);
        for(auto p: prerequisites) {
            adj[p[1]].push_back(p[0]);
        }
        for(int i=0; i<numCourses; ++i) {
            if(!vis[i] && dfs(i)) {
                return false;
            }
        }
        return true;
    }
};
