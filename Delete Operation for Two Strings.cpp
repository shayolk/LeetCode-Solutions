class Solution {
    int n, m;
    int lcs(string word1, string word2) {
        vector<vector<int>> dp(n+1, vector<int> (m+1));
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=m; ++j) {
                dp[i][j]=max({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                if(word1[i-1]==word2[j-1]) {
                    dp[i][j]=1+dp[i-1][j-1];
                }
            }
        }
        return dp[n][m];
    }
    
public:
    int minDistance(string word1, string word2) {
        n=word1.size();
        m=word2.size();
        int l=lcs(word1, word2);
        return n+m-2*l;
    }
};
