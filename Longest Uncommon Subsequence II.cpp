class Solution {
    bool issub(string a, string b) {
        int i=0, n=a.size();
        for(char c: b) {
            if(i<n && a[i]==c) {
                ++i;
            }
        }
        return i==n;
    }
    
public:
    int findLUSlength(vector<string>& strs) {
        int len=-1, n=strs.size();
        for(int i=0; i<n; ++i) {
            bool flag=true;
            for(int j=0; j<n; ++j) {
                if(i!=j && issub(strs[i], strs[j])) {
                    flag=false;
                    break;
                }
            }
            if(flag) len=max(len, (int)strs[i].size());
        }
        return len;
    }
};
