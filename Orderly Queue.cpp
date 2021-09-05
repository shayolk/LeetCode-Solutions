class Solution {
    string find(string s) {
        string ans=s;
        int n=s.size();
        for(int i=0; i<n; ++i) {
            s=s.substr(1, n)+s[0];
            ans=min(ans, s);
        }
        return ans;
    }
    
public:
    string orderlyQueue(string s, int k) {
        if(k==1) return find(s);
        sort(s.begin(), s.end());
        return s;
    }
};
