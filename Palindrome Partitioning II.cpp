class Solution {
public:
    int minCut(string s) {
        int n=s.size();
        vector<vector<bool>> pal(n+1, vector<bool> (n+1));
        for(int i=1; i<=n; ++i) {
            pal[i][i]=true;
            if(i>=2 && s[i-2]==s[i-1]) {
                pal[i-1][i]=true;
            }
        }
        for(int gap=2; gap<n; ++gap) {
            for(int i=1; i+gap<=n; ++i) {
                int j=i+gap;
                pal[i][j]=pal[i+1][j-1] && s[i-1]==s[j-1];
            }
        }
        vector<int> dp(n+1);
        for(int i=1; i<=n; ++i) {
            if(pal[1][i]) {
                dp[i]=0;
            }
            else {
                dp[i]=i-1;
                for(int j=1; j<=i; ++j) {
                    if(pal[j][i]) {
                        dp[i]=min(dp[i], 1+dp[j-1]);
                    }
                }
            }
        }
        return dp[n];
    }
};
