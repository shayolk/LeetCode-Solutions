class Solution {
public:
    string reorganizeString(string s) {
        int n=s.size();
        map<char,int> cnt;
        for(char c: s) {
            ++cnt[c];
        }
        vector<pair<int,char>> vp;
        for(auto c: cnt) {
            if(c.second>(n+1)/2) return "";
            vp.push_back({c.second, c.first});
        }
        sort(vp.rbegin(), vp.rend());
        s.clear();
        for(auto p: vp) {
            s+=string(p.first, p.second);
        }
        string ans;
        for(int i=0; i<n/2; ++i) {
            ans+=s[i];
            ans+=s[i+(n+1)/2];
        }
        if(n%2) ans+=s[n/2];
        return ans;
    }
};
