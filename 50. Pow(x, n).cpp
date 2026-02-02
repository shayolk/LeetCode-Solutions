class Solution {
public:
    double myPow(double x, long long n) {
        if (n == 0) {
            return 1.0;
        }
        if (x == 0.0 || x == 1.0) {
            return x;
        }
        if (n < 0) {
            return myPow(1.0 / x, -n);
        }
        return (n % 2 ? x : 1.0) * myPow(x * x, n / 2);
    }
};
