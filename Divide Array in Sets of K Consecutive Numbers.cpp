class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int,int> mp;
        for(int n: nums) {
            ++mp[n];
        }
        auto i=mp.begin();
        while(i!=mp.end()) {
            if(!i->second) {
                ++i;
                continue;
            }
            for(int g=0; g<k; ++g) {
                if(!mp[i->first+g]) return false;
                --mp[i->first+g];
            }
        }
        return true;
    }
};
