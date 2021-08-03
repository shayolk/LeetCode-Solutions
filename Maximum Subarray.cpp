class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx=INT_MIN,so=0;
        for(int i: nums)
        {
            so=max(i,so+i);
            mx=max(mx,so);
        }
        return mx;
    }
};
