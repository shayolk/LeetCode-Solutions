class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-2]!=nums[n-1]) return nums[n-1];
        int lo=1, hi=n-2, mid;
        while(lo<=hi) {
            mid=lo+(hi-lo)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]) return nums[mid];
            int l=mid+(nums[mid]==nums[mid-1]);
            if(l%2) hi=mid-1;
            else lo=mid+1;
        }
        return -1;
    }
};
