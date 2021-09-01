class Solution {
    int ans=0;
    vector<bool> vis;
    
    void dfs(int now, int dep, vector<int>& nums) {
        if(vis[now]) {
            ans=max(ans, dep);
            return;
        }
        vis[now]=true;
        dfs(nums[now], dep+1, nums);
    }
    
public:
    int arrayNesting(vector<int>& nums) {
        int n=nums.size();
        vis.resize(n);
        for(int i=0; i<n; ++i) {
            if(!vis[i]) {
                dfs(i, 0, nums);
            }
        }
        return ans;
    }
};
