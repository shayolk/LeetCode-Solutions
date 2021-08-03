class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        n /= 2;
        unordered_map<int,int> m;
        for(int x: nums) {
            ++m[x];
            if(m[x]>n) {
                return x;
            }
        }
        return 0;
    }
};
