class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size(), ans=1, nax=*max_element(nums.begin(), nums.end());
        vector<vector<int>> dp(n, vector<int> (2*nax+1, 1));
        for(int i=1; i<n; ++i) {
            for(int j=0; j<i; ++j) {
                int cd=nums[i]-nums[j]+nax;
                dp[i][cd]=max(dp[i][cd], 1+dp[j][cd]);
                ans=max(ans, dp[i][cd]);
            }
        }
        return ans;
    }
};
