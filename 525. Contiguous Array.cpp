class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for (int& num: nums) {
            if (!num) {
                num = -1;
            }
        }
        int n = nums.size();
        int sum = 0, ans = 0;
        vector<int> ind(2 * n + 1, -1);
        ind[n] = 0;
        for (int i = 1; i <= n; ++i) {
            sum += nums[i - 1];
            if (ind[sum + n] != -1) {
                ans = max(ans, i - ind[sum + n]);
            } else {
                ind[sum + n] = i;
            }
        }
        return ans;
    }
};
