class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = prices[0];
        int ans = 0;
        for (int p: prices) {
            ans = max(ans, p - mn);
            mn = min(mn, p);
        }
        return ans;
    }
};
