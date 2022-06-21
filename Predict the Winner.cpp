class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n, vector<int> (n));
        for(int i=0; i<n; ++i) {
            dp[i][i]=nums[i];
        }
        for(int gap=2; gap<=n; ++gap) {
            for(int i=0; i+gap-1<n; ++i) {
                int j=i+gap-1;
                dp[i][j]=max(nums[i]-dp[i+1][j], nums[j]-dp[i][j-1]);
            }
        }
        return dp[0][n-1]>=0;
    }
};
