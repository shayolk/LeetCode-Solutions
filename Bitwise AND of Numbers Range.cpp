class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int ans=0;
        for(int i=30; i>=0; --i) {
            if((m&(1<<i))!=(n&(1<<i)))
                break;
            ans|=(m&(1<<i));
        }
        return ans;
    }
};
