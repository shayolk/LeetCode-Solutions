class Solution {
    const int INF=1e9+5;
    
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INF);
        dp[0]=0;
        for(long long i=0; i<amount; ++i) {
            for(int coin: coins) {
                if(i+coin<=amount) {
                    dp[i+coin]=min(dp[i+coin], dp[i]+1);
                }
            }
        }
        if(dp[amount]==INF) dp[amount]=-1;
        return dp[amount];
    }
};
