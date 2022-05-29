class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int cnt=0, n=s.size();
        string ans;
        for(int i=n-1; i>=0; --i) {
            if(isalpha(s[i])) {
                ans+=toupper(s[i]);
                ++cnt;
            }
            else if(isdigit(s[i])) {
                ans+=s[i];
                ++cnt;
            }
            if(cnt==k) {
                ans+='-';
                cnt=0;
            }
        }
        if(ans.back()=='-') ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
