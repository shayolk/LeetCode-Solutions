class Solution {
public:
    string decodeString(string s) {
        int n=s.size();
        if(!n) return s;
        int i=0;
        string ret;
        while(i<n) {
            string rep;
            while(i<n && isalpha(s[i])) {
                ret+=s[i++];
            }
            if(i==n) break;
            int num=0;
            while(i<n && isdigit(s[i])) {
                num=10*num+(s[i++]-'0');
            }
            int j=++i, cnt=1;
            while(j<n && cnt) {
                if(s[j]=='[') ++cnt;
                if(s[j]==']') --cnt;
                ++j;
            }
            --j;
            string rec=decodeString(s.substr(i, j-i));
            while(num--) {
                ret+=rec;
            }
            i=j+1;
        }
        return ret;
    }
};
