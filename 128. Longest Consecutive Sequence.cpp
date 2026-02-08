class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> si(nums.begin(), nums.end());
        int ans = 0;
        for (int num: si) {
            if (si.count(num - 1)) {
                continue;
            }
            int cnt = 1;
            while (si.count(++num)) {
                ++cnt;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
