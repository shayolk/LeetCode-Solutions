class Solution {
public:
    int myAtoi(string s) {
        int ind=0, n=s.size();
        while(ind<n && s[ind]==' ') ++ind;
        bool neg=false;
        if(ind<n && (s[ind]=='+' || s[ind]=='-')) {
            if(s[ind]=='-') neg=true;
            ++ind;
        }
        if(ind<n && !isdigit(s[ind])) return 0;
        long long ans=0;
        while(ind<n) {
            if(!isdigit(s[ind])) break;
            ans=10*ans+(s[ind]-'0');
            if(ans>INT_MAX) ans=1ll+INT_MAX;
            ++ind;
        }
        if(neg) {
            if(ans==1ll+INT_MAX) ans=INT_MIN;
            else ans*=-1;
        }
        if(ans==1ll+INT_MAX) ans=INT_MAX;
        return (int)ans;
    }
};
