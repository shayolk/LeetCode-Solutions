class Solution {
public:
    double myPow(double x, int n) {
        if(x==0) return 0;
        double res=1.0;
        while(n) {
            if(n%2) {
                if(n>=0) res*=x;
                else res/=x;
            }
            x*=x;
            n/=2;
        }
        return res;
    }
};
