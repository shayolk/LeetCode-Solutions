class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 4) {
            return {};
        }
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        for (int i = 0; i < n - 3; ++i) {
            for (int j = i + 1; j < n - 2; ++j) {
                long long ij = nums[i] + nums[j];
                int l = j + 1, r = n - 1;
                while (l < r) {
                    long long lr = nums[l] + nums[r];
                    if (ij + lr < target) {
                        ++l;
                    } else if (ij + lr > target) {
                        --r;
                    } else {
                        ans.insert({nums[i], nums[j], nums[l++], nums[r--]});
                    }
                }
            }
        }
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};
