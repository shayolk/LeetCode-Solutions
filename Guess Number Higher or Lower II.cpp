class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n, vector<int> (n));
        for(int i=1; i<n; ++i) {
            dp[i-1][i]=i;
        }
        for(int gap=2; gap<n; ++gap) {
            for(int i=0; i+gap<n; ++i) {
                int j=i+gap;
                dp[i][j]=min(i+1+dp[i+1][j], dp[i][j-1]+j+1);
                for(int k=i+1; k<j; ++k) {
                    dp[i][j]=min(dp[i][j], k+1+max(dp[i][k-1], dp[k+1][j]));
                }
            }
        }
        return dp[0][n-1];
    }
};
