class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size(), lo=0, hi=nums.size()-1, mid;
        mid=lo+(hi-lo)/2;
        while(lo<=hi)
        {
            if(target==nums[mid])
                return mid;
            else if(target==nums[lo])
                return lo;
            else if(target==nums[hi])
                return hi;
            else if(nums[mid]>nums[lo]) {
                if(target<nums[mid]) {
                    if(target>nums[lo])
                        hi=mid-1;
                    else
                        lo=mid+1;
                }
                else 
                    lo=mid+1;
            }
            else {
                if(target>nums[mid]) {
                    if(target<nums[hi])
                        lo=mid+1;
                    else
                        hi=mid-1;
                }
                else
                    hi=mid-1;
            }
            mid=lo+(hi-lo)/2;
        }
        return -1;
    }
};
