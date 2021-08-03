class Solution {
public:
    int findComplement(int num) {
        int ans = 0;
        bool flag = false;
        for(int bit = 31; bit >= 0; --bit) {
            if(num & (1 << bit)) {
                flag = true;
            }
            if(flag) {
                ans |= ((num & (1 << bit)) ^ (1 << bit));
            }
        }
        return ans;
    }
};
