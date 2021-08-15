class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size(), m=t.size();
        vector<int> ms(256), mt(256);
        for(char c: t) {
            ++mt[c];
        }
        int len=n+1, ind=-1, st=0, cnt=0;
        for(int i=0; i<n; ++i) {
            ++ms[s[i]];
            if(ms[s[i]]<=mt[s[i]]) {
                ++cnt;
            }
            if(cnt==m) {
                while(!mt[s[st]] || mt[s[st]]<ms[s[st]]) {
                    if(mt[s[st]]<ms[s[st]]) {
                        --ms[s[st]];
                    }
                    ++st;
                }
                if(i-st+1<len) {
                    len=i-st+1;
                    ind=st;
                }
            }
        }
        if(ind==-1) return "";
        return s.substr(ind, len);
    }
};
