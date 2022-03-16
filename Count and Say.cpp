class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string last=countAndSay(n-1);
        string ans;
        char c='#';
        int cnt=0;
        for(char s: last) {
            if(c!=s) {
                if(cnt) ans+=to_string(cnt)+string(1, c);
                c=s;
                cnt=1;
            }
            else {
                ++cnt;
            }
        }
        if(cnt) ans+=to_string(cnt)+string(1, c);
        return ans;
    }
};
