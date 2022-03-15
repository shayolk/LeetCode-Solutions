class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        int m=needle.size();
        needle+="#"+haystack;
        int n=needle.size();
        vector<int> lps(n);
        for(int i=1; i<n; ++i) {
            int j=lps[i-1];
            while(j && needle[i]!=needle[j]) {
                j=lps[j-1];
            }
            if(needle[i]==needle[j]) ++j;
            lps[i]=j;
            if(lps[i]==m) return i-2*m;
        }
        return -1;
    }
};
