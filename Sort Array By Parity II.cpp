class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int i=0, j=0, n=nums.size();
        while(i<n && j<n) {
            while(i<n && (i%2 || (i%2==nums[i]%2))) {
                ++i;
            }
            while(j<n && (j%2==0 || (j%2==nums[j]%2))) {
                ++j;
            }
            if(i<n && j<n) {
                swap(nums[i++], nums[j++]);
            }
        }
        return nums;
    }
};
