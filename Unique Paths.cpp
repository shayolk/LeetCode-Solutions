class Solution {
public:
    int uniquePaths(int m, int n) {
        int step=n-1, tot=m+n-2;
        long double ans=1;
        for(int i=1; i<=step; ++i) {
            ans=ans*(tot-step+i)/i;
        }
        return (int)ans;
    }
};
