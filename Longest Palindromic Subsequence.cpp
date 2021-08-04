class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1));
        for(int i=1; i<=n; ++i) {
            dp[i][i]=1;
        }
        for(int gap=1; gap<n; ++gap) {
            for(int i=1; i+gap<=n; ++i) {
                int j=i+gap;
                if(s[i-1]==s[j-1]) {
                    dp[i][j]=2+dp[i+1][j-1];
                }
                else {
                    dp[i][j]=max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[1][n];
    }
};
