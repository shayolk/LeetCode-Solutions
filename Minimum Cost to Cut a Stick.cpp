class Solution {
    const int INF=1e9+5;
    
public:
    int minCost(int n, vector<int>& cuts) {
        int m=cuts.size();
        vector<vector<int>> dp(m+2, vector<int>(m+2));
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        for(int gap=1; gap<=m; ++gap) {
            for(int l=1; l+gap-1<=m; ++l) {
                int r=l+gap-1;
                dp[l][r]=INF;
                for(int cut=l; cut<=r; ++cut) {
                    dp[l][r]=min(dp[l][r], cuts[r+1]-cuts[l-1]+dp[l][cut-1]+dp[cut+1][r]);
                }
            }
        } 
        return dp[1][m];
    }
};
