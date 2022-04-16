class Solution {
    const int INF=1e9+5;
    
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1, INF);
        dp[0]=-INF;
        for(int i=0; i<n; ++i) {
            int j=upper_bound(dp.begin(), dp.end(), nums[i])-dp.begin();
            if(dp[j-1]<nums[i] && nums[i]<dp[j]) {
                dp[j]=nums[i];
            }
        }
        int ans=1;
        for(int i=0; i<=n; ++i) {
            if(dp[i]<INF) {
                ans=i;
            }
        }
        return ans;
    }
};
