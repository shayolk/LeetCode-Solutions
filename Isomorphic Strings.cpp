class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size();
        map<char,char> mp;
        set<char> done;
        for(int i=0; i<n; ++i) {
            if(mp.count(s[i])) {
                if(t[i]!=mp[s[i]]) return false;
                continue;
            }
            if(done.count(t[i])) return false;
            mp[s[i]]=t[i];
            done.insert(t[i]);
        }
        return true;
    }
};
