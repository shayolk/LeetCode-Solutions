class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int> suff(n+1);
        for(int i=n-1; i>=0; --i) {
            suff[i]=nums[i]+suff[i+1];
        }
        int pref=0;
        for(int i=0; i<n; ++i) {
            if(suff[i+1]==pref) return i;
            pref+=nums[i];
        }
        return -1;
    }
};
