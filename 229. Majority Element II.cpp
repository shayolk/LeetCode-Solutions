class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> ans;
        for (int id: {n / 3, 2 * (n / 3) + 1}) {
            if (id >= n) {
                break;
            }
            int cnt = 0, val = nums[id];
            for (int num: nums) {
                if (num == val) {
                    ++cnt;
                }
            }
            if (cnt > n / 3 && (ans.empty() || ans[0] != val)) {
                ans.push_back(val);
            }
        }
        return ans;
    }
};
