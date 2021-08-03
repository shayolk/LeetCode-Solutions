class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=(int)prices.size();
        if(n==0) return 0;
        int ans=0, buy=prices[0];
        for(int i=1; i<n; ++i) {
            ans=max(ans, prices[i]-buy);
            buy=min(buy, prices[i]);
        }
        return ans;
    }
};
