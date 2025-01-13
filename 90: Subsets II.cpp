class Solution {
    int n;
    set<vector<int>> sets;

    void findSubsets(int ind, vector<int>& nums, vector<int> now) {
        if(ind == n) {
            sort(now.begin(), now.end());
            sets.insert(now);
            return;
        }
        findSubsets(ind+1, nums, now);
        now.push_back(nums[ind]);
        findSubsets(ind+1, nums, now);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n = nums.size();
        vector<int> now;
        findSubsets(0, nums, now);
        return vector<vector<int>> (sets.begin(), sets.end());
    }
};
