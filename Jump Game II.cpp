class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size(), last=0, end=0, jump=0;
        for(int i=0; i<n-1; ++i) {
            last=max(last, i+nums[i]);
            if(i==end) {
                ++jump;
                end=last;
            }
        }
        return jump;
        
        // int n=nums.size();
        // vector<int> dp(n, 1e9+5);
        // dp[0]=0;
        // for(int i=0; i<n; ++i) {
        //     for(int j=1; j<=nums[i] && i+j<n; ++j) {
        //         dp[i+j]=min(dp[i+j], 1+dp[i]);
        //     }
        // }
        // return dp[n-1];
    }
};
