class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int lo=0, hi=n-1;
        while(lo<=hi) {
            int mid=lo+(hi-lo)/2;
            if(nums[mid]==target) return mid;
            if(target<nums[mid]) {
                if(nums[0]<=nums[mid]) {
                    if(nums[lo]<=target && target<nums[mid]) hi=mid-1;
                    else lo=mid+1;
                }
                else {
                    if(nums[mid]<target && target<=nums[hi]) lo=mid+1;
                    else hi=mid-1;
                }
            }
            else {
                if(nums[mid]<=nums[n-1]) {
                    if(nums[mid]<target && target<=nums[hi]) lo=mid+1;
                    else hi=mid-1;
                }
                else {
                    if(nums[lo]<=target && target<nums[mid]) hi=mid-1;
                    else lo=mid+1;
                }
            }
        }
        return -1;
    }
};
