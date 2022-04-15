class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=-1e9-5, somax=1, somin=1;
        for(int n: nums) {
            int mx=somax*n, mn=somin*n;
            somax=max({n, mx, mn});
            somin=min({n, mx, mn});
            ans=max({ans, somax, somin});
            if(n==0) {
                somax=1;
                somin=1;
            }
        }
        return ans;
    }
};
