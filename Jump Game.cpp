class Solution {
public:
    bool canJump(vector<int>& nums) {
        const int n=nums.size();
        int ind=n-1;
        for(int i=n-2; i>=0; --i) {
            if(nums[i]>=ind-i)
                ind=i;
        }
        if(ind)
            return false;
        return true;
        
        /*vector<bool> jump(n);
        jump[0]=true;
        if(jump[n-1])
            return true;
        for(int i=0; i<n-1; ++i) {
            if(!jump[i])
                continue;
            if(nums[i]>=n-1-i)
                return true;
            for(int j=1; j<=nums[i]; ++j) {
                if(i+j>=n)
                    break;
                jump[i+j]=true;
                if(jump[n-1])
                    return true;
            }
        }
        return jump[n-1];*/
    }
};
