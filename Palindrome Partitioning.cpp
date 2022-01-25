class Solution {
    int n;
    vector<vector<bool>> pal;
    vector<vector<string>> ans;
    
    void find(int i, string& s, vector<string>& now) {
        if(i==n) {
            if(!now.empty()) ans.push_back(now);
            return;
        }
        for(int j=i; j<n; ++j) {
            if(pal[i][j]) {
                now.push_back(s.substr(i, j-i+1));
                find(j+1, s, now);
                now.pop_back();
            }
        }
    }
    
public:
    vector<vector<string>> partition(string s) {
        n=s.size();
        pal.resize(n, vector<bool> (n));
        for(int i=0; i<n; ++i) {
            pal[i][i]=true;
            if(i && s[i-1]==s[i]) pal[i-1][i]=true;
        }
        for(int l=3; l<=n; ++l) {
            for(int i=0; i+l-1<n; ++i) {
                int j=i+l-1;
                pal[i][j]=s[i]==s[j] && pal[i+1][j-1];
            }
        }
        vector<string> v;
        find(0, s, v);
        return ans;
    }
};
