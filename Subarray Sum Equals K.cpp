class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        m[0]=1;
        int sum=0, ans=0;
        for(int x: nums) {
            sum+=x;
            ans+=m[sum-k];
            ++m[sum];
        }
        return ans;
    }
};
