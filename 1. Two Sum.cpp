class Solution {
    using pii = pair<int,int>;

public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pii> vp(n);
        for (int i = 0; i < n; ++i) {
            vp[i] = {nums[i], i};
        }
        sort(vp.begin(), vp.end());
        int l = 0, r = n - 1;
        while (l < r) {
            if (vp[l].first + vp[r].first == target) {
                return {vp[l].second, vp[r].second};
            }
            if (vp[l].first + vp[r].first < target) {
                ++l;
            } else {
                --r;
            }
        }
        return {-1, -1};
    }
};
