class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0, so=0;
        for(int n: nums) {
            if(n==1) ++so;
            else so=0;
            ans=max(ans, so);
        }
        return ans;
    }
};
