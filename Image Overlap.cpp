class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size(), m=img1[0].size();
        vector<pair<int,int>> vp1, vp2;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(img1[i][j]) vp1.push_back({i, j});
                if(img2[i][j]) vp2.push_back({i, j});
            }
        }
        map<pair<int,int>,int> cnt;
        for(auto p1: vp1) {
            for(auto p2: vp2) {
                ++cnt[{p1.first-p2.first, p1.second-p2.second}];
            }
        }
        int ans=0;
        for(auto c: cnt) {
            ans=max(ans, c.second);
        }
        return ans;
    }
};
