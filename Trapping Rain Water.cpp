class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(), ans=0;
        int l=0, r=n-1, maxl=0, maxr=0;
        while(l<=r) {
            if(height[l]<=height[r]) {
                if(height[l]<maxl) ans+=maxl-height[l];
                else maxl=height[l];
                ++l;
            }
            else {
                if(height[r]<maxr) ans+=maxr-height[r];
                else maxr=height[r];
                --r;
            }
        }
        return ans;
    }
};
