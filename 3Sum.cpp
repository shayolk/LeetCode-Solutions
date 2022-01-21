class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        set<vector<int>> ans;
        for(int i=0; i<n; ++i) {
            int j=i+1, k=n-1;
            while(j<k) {
                int sum=nums[i]+nums[j]+nums[k];
                if(sum>0) {
                    --k;
                }
                else if (sum<0){
                    ++j;
                }
                else {
                    ans.insert(vector<int>{nums[i], nums[j], nums[k]});
                    ++j;
                    --k;
                }
            }
        }
        vector<vector<int>> ret;
        for(auto s: ans) {
            ret.push_back(s);
        }
        return ret;
    }
};
