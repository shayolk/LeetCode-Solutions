class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(), nums.end(), 0);
        if(sum%2) return false;
        vector<bool> dp(sum+1);
        dp[0]=true;
        for(int n: nums) {
            vector<int> ind;
            for(int i=0; i<sum; ++i) {
                if(dp[i] && i+n<=sum) {
                    ind.push_back(i+n);
                }
            }
            for(int i: ind) {
                dp[i]=true;
            }
        }
        return dp[sum/2];
    }
};
