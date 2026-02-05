class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int val = 0, cnt = 0;
        for (int num: nums) {
            if (cnt == 0) {
                val = num;
            }
            if (num == val) {
                ++cnt;
            } else {
                --cnt;
            }
        }
        return val;
    }
};
