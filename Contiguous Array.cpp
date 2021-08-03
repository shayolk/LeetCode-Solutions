class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        if(nums.size()<2) {
            return 0;
        }
        int n=nums.size();
        for(int i=0; i<n; ++i) {
            if(!nums[i]) {
                nums[i]=-1;
            }
        }
        vector <int> a(2*n+1,-2);
        int sum=0,mx=0;
        a[n]=-1;
        for(int i=0; i<n; ++i) {
            sum+=nums[i];
            if(a[sum+n]!=-2) {
                mx=max(mx,i-a[sum+n]);
            }
            else {
                a[sum+n]=i;
            }
        }
        return mx;
    }
};
