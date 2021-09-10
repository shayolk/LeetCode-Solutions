class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        vector<map<long long, int>> dp(n);
        for(int i=1; i<n; ++i) {
            for(int j=0; j<i; ++j) {
                long long cd=(long long)nums[i]-nums[j];
                dp[i][cd]+=1;
                if(dp[j].count(cd)) {
                    ans+=dp[j][cd];
                    dp[i][cd]+=dp[j][cd];
                }
            }
        }
        return ans;
    }
};
