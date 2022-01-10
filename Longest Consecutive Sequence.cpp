class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> hash;
        for(int i: nums) {
            hash.insert(i);
        }
        int ans=0;
        for(int i: nums) {
            if(hash.count(i-1)) {
                continue;
            }
            int cnt=1, num=i;
            while(hash.count(num+1)) {
                ++cnt;
                ++num;
            }
            ans=max(ans, cnt);
        }
        return ans;
    }
};
