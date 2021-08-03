class Solution {
    void permute(int i, int n, multiset<int> now, vector<int>& nums, set<multiset<int>>& ans) {
        if(i==n) {
            ans.insert(now);
            return;
        }
        permute(i+1, n, now, nums, ans);
        now.insert(nums[i]);
        permute(i+1, n, now, nums, ans);
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        set<multiset<int>> ans;
        permute(0, n, multiset<int>{}, nums, ans);
        vector<vector<int>> ret;
        for(auto s: ans) {
            vector<int> v(s.begin(), s.end());
            ret.push_back(v);
        }
        return ret;
    }
};
