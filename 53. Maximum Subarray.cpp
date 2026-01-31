class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = -1e9;
        int so = 0;
        for(int ni: nums) {
            so = max(ni, so + ni);
            sum = max(sum, so);
        }
        return sum;
    }
};
