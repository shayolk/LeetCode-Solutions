class Solution {
    int n;
    vector<vector<int>> sets;

    void findSubsets(int ind, vector<int>& nums, vector<int>& now) {
        sets.push_back(now);
        for(int i=ind; i<n; ++i) {
            if(i != ind && nums[i] == nums[i-1]) {
                continue;
            }
            now.push_back(nums[i]);
            findSubsets(i+1, nums, now);
            now.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n = nums.size();
        vector<int> now;
        sort(nums.begin(), nums.end());
        findSubsets(0, nums, now);
        return sets;
    }
};
