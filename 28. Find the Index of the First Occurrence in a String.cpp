class Solution {
public:
    int strStr(string haystack, string needle) {
        haystack = needle + '-' + haystack;
        int n = haystack.size();
        int m = needle.size();
        vector<int> z(n);
        int l = 0, r = 0;
        for(int i = 1; i < n; ++i) {
            if(i < r) {
                z[i] = min(r - i, z[i - l]);
            }
            while(i + z[i] < n && haystack[z[i]] == haystack[i + z[i]]) {
                ++z[i];
            }
            if(i + z[i] > r) {
                l = i;
                r = i + z[i];
            }
        }
        for(int i = m + 1; i < n; ++i) {
            if(z[i] == m) {
                return (i - m - 1);
            }
        }
        return -1;
    }
};
