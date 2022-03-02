class Solution {
public:
    string reverseWords(string s) {
        string ans, now;
        for(char c: s) {
            if(c==' ') {
                if(!now.empty()) ans=now+(!ans.empty()?" ":"")+ans;
                now.clear();
            }
            else {
                now+=c;
            }
        }
        if(!now.empty()) ans=now+(!ans.empty()?" ":"")+ans;
        return ans;
    }
};
