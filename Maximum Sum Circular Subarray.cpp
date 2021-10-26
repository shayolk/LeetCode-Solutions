class Solution {
    const int INF=1e9+5;
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size(), ans=-INF, so=0;
        for(int i: nums) {
            so=max(i, so+i);
            ans=max(ans, so);
        }
        vector<int> suff(n);
        so=suff[n-1]=nums[n-1];
        for(int i=n-2; i>=0; --i) {
            so+=nums[i];
            suff[i]=max(suff[i+1], so);
        }
        so=0;
        for(int i=0; i<n-2; ++i) {
            so+=nums[i];
            ans=max(ans, so+suff[i+2]);
        }
        return ans;
    }
};
