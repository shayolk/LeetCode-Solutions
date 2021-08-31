class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int lo=0, hi=n-1, mid;
        while(lo<=hi) {
            mid=lo+(hi-lo)/2;
            int l=mid>0?mid-1:n-1, r=mid+1<n?mid+1:0;
            if(nums[l]>nums[mid] && nums[mid]<nums[r]) {
                return nums[mid];
            }
            if(nums[mid]>nums[hi]) {
                lo=mid+1;
            }
            else {
                hi=mid-1;
            }
        }
        return nums[mid];
    }
};
