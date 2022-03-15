class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size(), m=needle.size();
        if(!m) return 0;
        vector<int> lps(m);
        for(int i=1; i<m; ++i) {
            int j=lps[i-1];
            while(j && needle[i]!=needle[j]) {
                j=lps[j-1];
            }
            if(needle[i]==needle[j]) ++j;
            lps[i]=j;
        }
        int i=0, j=0;
        while(i<n) {
            if(haystack[i]==needle[j]) {
                ++i;
                ++j;
            }
            else {
                if(j) j=lps[j-1];
                else ++i;
            }
            if(j==m) return i-m;
        }
        return -1;
    }
};
