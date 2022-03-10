class Solution {
    string find(int st, int ed, vector<string>& s) {
        if(st==ed) return s[st];
        int mid=st+(ed-st)/2;
        string l=find(st, mid, s), r=find(mid+1, ed, s);
        int n=l.size(), m=r.size();
        string res;
        for(int i=0; i<min(n, m); ++i) {
            if(l[i]!=r[i]) break;
            res+=l[i];
        }
        return res;
    }
    
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        return find(0, n-1, strs);
    }
};
