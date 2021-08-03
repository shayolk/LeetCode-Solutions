class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=(int)prices.size();
        if(n<=1) return 0;
        vector<int> left(n), right(n);
        int so=prices[0];
        for(int i=1; i<n; ++i) {
            left[i]=max(left[i-1], prices[i]-so);
            so=min(so, prices[i]);
        }
        so=prices[n-1];
        for(int i=n-2; i>=0; --i) {
            right[i]=max(right[i+1], so-prices[i]);
            so=max(so, prices[i]);
        }
        int ans=left[n-1];
        for(int i=0; i<n-1; ++i) {
            ans=max(ans, left[i]+right[i+1]);
        }
        return ans;
    }
};
