class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int patch=0, i=0, len=nums.size();
        long long end=0;
        while(end<n) {
            if(i<len && nums[i]<=end+1) {
                end+=nums[i++];
            }
            else {
                end+=end+1;
                ++patch;
            }
        }
        return patch;
    }
};
