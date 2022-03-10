class Solution {
public:
    int minOperations(vector<int>& nums) {
        int s=nums.size();
        sort(nums.begin(), nums.end());
        int n=unique(nums.begin(), nums.end())- nums.begin();
        int ans=s;
        for(int i=0; i<n; ++i) {
            int up=nums[i]+s-1;
            int ind=upper_bound(nums.begin(), nums.begin()+n, up)-nums.begin();
            ans=min(ans, s-ind+i);
        }
        return ans;
    }
};
