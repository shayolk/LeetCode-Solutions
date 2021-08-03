class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0, j=0, ans=0, n=(int)s.size();
        map<char,int> m;
        while(j<n) {
            // cout<<i<<" "<<j<<"\n";
            if(m.count(s[j])) {
                i=max(i, m[s[j]]+1);
            }
            // cout<<i<<" "<<j<<"\n\n";
            ans=max(ans, j-i+1);
            m[s[j]]=j;
            ++j;
        }
        return ans;
    }
};
