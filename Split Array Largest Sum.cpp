class Solution {
    bool check(int per, vector<int>& nums, int m, int n) {
        int cnt=1, now=nums[0];
        for(int i=1; i<n; ++i) {
            if(now+nums[i]>per) {
                ++cnt;
                now=nums[i];
            }
            else {
                now+=nums[i];
            }
        }
        return cnt<=m;
    }
    
public:
    int splitArray(vector<int>& nums, int m) {
        int lo=0, hi=0, n=nums.size();
        for(int num: nums) {
            lo=max(lo, num);
            hi+=num;
        }
        int ans=hi;
        while(lo<=hi) {
            int mid=lo+(hi-lo)/2;
            if(check(mid, nums, m, n)) {
                ans=mid;
                hi=mid-1;
            }
            else {
                lo=mid+1;
            }
        }
        return ans;
    }
};
