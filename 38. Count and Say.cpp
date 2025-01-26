class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) {
            return "1";
        }
        string s = countAndSay( n - 1);
        string res;
        char now = s[0];
        int cnt = 0;
        for(char c: s) {
            if(c == now) {
                ++cnt;
            }
            else {
                res += to_string(cnt);
                res += now;
                now = c;
                cnt = 1;
            }
        }
        res += to_string(cnt);
        res += now;
        return res;
    }
};
