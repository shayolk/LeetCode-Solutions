class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n=s.size();
        vector<int> zero(n), one(n);
        one[0]=s[0]=='1';
        for(int i=1; i<n; ++i) {
            one[i]=one[i-1]+(s[i]=='1');
        }
        zero[n-1]=s[n-1]=='0';
        for(int i=n-2; i>=0; --i) {
            zero[i]=zero[i+1]+(s[i]=='0');
        }
        int ans=min(zero[0], one[n-1]);
        for(int i=0; i<n-1; ++i) {
            ans=min(ans, one[i]+zero[i+1]);
        }
        return ans;
    }
};
