class Solution {
    static bool cmp(const string& a, const string& b) {
        if((int)a.size()==(int)b.size()) return a<b;
        return (int)a.size()<(int)b.size();
    }
    
    bool check(string s, string d) {
        int n=s.size(), m=d.size();
        if(m-n!=1) return false;
        int i=0, j=0;
        while(i<n && j<m) {
            if(s[i]!=d[j]) {
                ++j;
                continue;
            }
            ++i;
            ++j;
        }
        return i==n && j>=m-1;
    }
    
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        int n=words.size();
        vector<vector<bool>> ispre(n, vector<bool> (n));
        for(int i=0; i<n; ++i) {
            for(int j=i+1; j<n; ++j) {
                ispre[i][j]=check(words[i], words[j]);
            }
        }
        vector<int> dp(n, 1);
        int ans=dp[0];
        for(int i=1; i<n; ++i) {
            for(int j=0; j<i; ++j) {
                if(ispre[j][i]) {
                    dp[i]=max(dp[i], 1+dp[j]);
                }
            }
            ans=max(ans, dp[i]);
        }
        return ans;
    }
};
