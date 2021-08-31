class Solution {
    const int INF=1e9+5;
public:
    int maxProfit(int K, vector<int>& prices) {
        int N=(int)prices.size();
        if(N<=1 || K==0) return 0;
        vector<vector<vector<int>>> dp(N+1, vector<vector<int>> (K+1, vector<int> (2, -INF)));
        for(int i=0; i<=N; ++i) {
            dp[i][0][1]=0;
        }
        for(int j=0; j<=K; ++j) {
            dp[0][j][1]=0;
        }
        for(int i=1; i<=N; ++i) {
            for(int j=1; j<=K; ++j) {
                dp[i][j][1]=max(dp[i-1][j][1], dp[i-1][j][0]+prices[i-1]);
                dp[i][j][0]=max(dp[i-1][j][0], dp[i-1][j-1][1]-prices[i-1]);
            }
        }
        int ans=0;
        for(int j=0; j<=K; ++j) {
            ans=max(ans, dp[N][j][1]);
        }
        return ans;
    }
};
