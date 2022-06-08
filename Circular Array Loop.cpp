class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n=nums.size();
        for(int i=0; i<n; ++i) {
            int j=i, sign=nums[i]>0, cnt=0;
            vector<bool> vis(n);
            do {
                int here=nums[j]>0;
                if(sign!=here) break;
                vis[j]=true;
                ++cnt;
                j+=nums[j];
                while(j<0) {
                    j+=n;
                }
                j%=n;
                if(j==i && cnt>1) return true;
            } while(!vis[j]);
        }
        return false;
    }
};
