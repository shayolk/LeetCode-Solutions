class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> mp;
        for(int h: hand) {
            ++mp[h];
        }
        auto i=mp.begin();
        while(i!=mp.end()) {
            if(!i->second) {
                ++i;
                continue;
            }
            for(int g=0; g<groupSize; ++g) {
                if(!mp[i->first+g]) return false;
                --mp[i->first+g];
            }
        }
        return true;
    }
};
