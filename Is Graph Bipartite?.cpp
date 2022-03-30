class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        stack<pair<int,int>> s;
        vector<bool> vis(n);
        vector<int> color(n, -1);
        for(int i=0; i<n; ++i) {
            if(vis[i]) continue;
            s.push({i, 0});
            vis[i]=true;
            color[i]=0;
            while(!s.empty()) {
                pair<int,int> p=s.top();
                s.pop();
                int now=p.first, col=p.second;
                for(int neb: graph[now]) {
                    if(color[neb]==col) return false;
                    if(vis[neb]) continue;
                    vis[neb]=true;
                    color[neb]=1-col;
                    s.push({neb, 1-col});
                }
            }
        }
        if(find(color.begin(), color.end(), -1)!=color.end()) return false;
        return true;
    }
};
