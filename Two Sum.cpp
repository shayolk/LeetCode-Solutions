class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> ind;
        for(int i=0; i<nums.size(); ++i) {
            if(ind.count(nums[i])) {
                return vector<int>{ind[nums[i]], i};
            }
            ind[target-nums[i]]=i;
        }
        return vector<int>{-1, -1};
    }
};
