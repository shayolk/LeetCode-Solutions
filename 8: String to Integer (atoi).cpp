class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        while(i < n && s[i] == ' ') {
            ++i;
        }
        if(i == n) {
            return 0;
        }
        bool neg = false;
        if(s[i] == '-' || s[i] == '+') {
            if(s[i] == '-') {
                neg = !neg;
            }
            ++i;
        }
        long long ans = 0;
        while(i < n) {
            if(s[i] < '0' || s[i] > '9') {
                break;
            }
            ans = (ans * 10) + (s[i] - '0');
            ++i;
            if(ans > INT_MAX) {
                if(neg) {
                    return INT_MIN;
                }
                return INT_MAX;
            }
        }
        if(neg) {
            return (int)(-ans);
        }
        return (int)ans;
    }
};
