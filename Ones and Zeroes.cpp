class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int s=strs.size();
        int cnt[s][2];
        for(int i=0; i<s; ++i) {
            cnt[i][0]=cnt[i][1]=0;
            for(char c: strs[i]) {
                ++cnt[i][c-'0'];
            }
        }
        vector<vector<int>> dp(m+1, vector<int> (n+1));
        for(int k=0; k<s; ++k) {
            for(int i=m; i>=0; --i) {
                for(int j=n; j>=0; --j) {
                    if(cnt[k][0]<=i && cnt[k][1]<=j) {
                        dp[i][j]=max(dp[i][j], dp[i-cnt[k][0]][j-cnt[k][1]]+1);
                    }
                }
            }
        }
        return dp[m][n];
    }
};
