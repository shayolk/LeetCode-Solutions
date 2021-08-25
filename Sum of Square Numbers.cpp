class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long long i=0; i*i<=c; ++i) {
            int left=c-i*i;
            int s=sqrt(left);
            if(s*s==left) return true;
        }
        return false;
    }
};
