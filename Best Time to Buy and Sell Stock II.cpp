class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=(int)prices.size();
        if(n==0) return 0;
        int ans=0, buy=prices[0], now=0;
        for(int i=1; i<n; ++i) {
            if(prices[i]<=prices[i-1]) {
                ans+=now;
                buy=prices[i];
                now=0;
            }
            else {
                now=max(now, prices[i]-buy);
                buy=min(buy, prices[i]);
            }
        }
        ans+=now;
        return ans;
    }
};
