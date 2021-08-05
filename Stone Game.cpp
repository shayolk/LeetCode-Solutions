class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>> dp(n+2, vector<int> (n+2));
        for(int gap=0; gap<=n; ++gap) {
            for(int i=1; i+gap<=n; ++i) {
                int j=i+gap;
                if(gap%2) {
                    dp[i][j]=max(piles[i-1]+dp[i+1][j], piles[j-1]+dp[i][j-1]);
                }
                else {
                    dp[i][j]=min(piles[i-1]+dp[i+1][j], piles[j-1]+dp[i][j-1]);
                }
            }
        }
        return dp[1][n]>min(dp[1][n-1], dp[2][n]);
    }
};
