class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int val=nums[0], cut=0;
        for(int i: nums) {
            if(cut==0) {
                val=i;
            }
            if(i==val) {
                ++cut;
            }
            else {
                --cut;
            }
        }
        return val;
    }
};
