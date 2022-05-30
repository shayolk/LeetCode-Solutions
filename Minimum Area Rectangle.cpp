class Solution {
    int INF=1e9+5;
    
public:
    int minAreaRect(vector<vector<int>>& points) {
        set<pair<int,int>> sp;
        for(auto point: points) {
            sp.insert({point[0], point[1]});
        }
        int n=points.size(), ans=INF;
        for(int i=0; i<n-1; ++i) {
            int x1=points[i][0], y1=points[i][1];
            for(int j=i+1; j<n; ++j) {
                int x2=points[j][0], y2=points[j][1];
                if(x1==x2 || y1==y2) continue;
                if(sp.count({x1, y2}) && sp.count({x2, y1})) {
                    ans=min(ans, abs(x1-x2)*abs(y1-y2));
                }
            }
        }
        if(ans==INF) ans=0;
        return ans;
    }
};
