class Solution {
    int n;
    vector<vector<int>> ans;
    
    void find(int pos, vector<int>& nums) {
        if(pos==n) {
            ans.push_back(nums);
            return;
        }
        for(int i=pos; i<n; ++i) {
            swap(nums[i], nums[pos]);
            find(pos+1, nums);
            swap(nums[i], nums[pos]);
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        n=nums.size();
        find(0,nums);
        return ans;
    }
};
