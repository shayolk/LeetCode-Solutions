class Solution {
    map<string,vector<string>> adjs;
    map<string,vector<double>> adjd;
    map<string,bool> vis;
    
    double dfs(string now, string end) {
        if(!adjs.count(now)) return -1.0;
        if(now==end) return 1.0;
        vis[now]=true;
        for(int neb=0; neb<adjs[now].size(); ++neb) {
            if(vis.count(adjs[now][neb]) && vis[adjs[now][neb]]) continue;
            double his=dfs(adjs[now][neb], end);
            if(his!=-1.0) return adjd[now][neb]*his;
        }
        vis[now]=false;
        return -1.0;
    }
    
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n=values.size();
        for(int i=0; i<n; ++i) {
            adjs[equations[i][0]].push_back(equations[i][1]);
            adjd[equations[i][0]].push_back(values[i]);
            adjs[equations[i][1]].push_back(equations[i][0]);
            adjd[equations[i][1]].push_back(1.0/values[i]);
        }
        vector<double> ans;
        for(auto query: queries) {
            vis.clear();
            ans.push_back(dfs(query[0], query[1]));
        }
        return ans;
    }
};
