class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(), ans=0;
        int right[n];
        right[n-1]=height[n-1];
        for(int i=n-2; i>=0; --i) {
            right[i]=max(height[i], right[i+1]);
        }
        int left=height[0];
        for(int i=1; i<n-1; ++i) {
            left=max(left, height[i]);
            ans+=min(left, right[i])-height[i];
        }
        return ans;
    }
};
