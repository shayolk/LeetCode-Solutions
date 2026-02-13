class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0, sum = 0;
        map<int,int> cnt;
        cnt[0] = 1;
        for (int num: nums) {
            sum += num;
            if (cnt.count(sum - k)) {
                ans += cnt[sum - k];
            }
            ++cnt[sum];
        }
        return ans;
    }
};
