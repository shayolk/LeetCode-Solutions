class Solution {
    const int INF=1e9+5;
    
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dp(n, vector<int> (n, -INF));
        dp[0][0]=grid[0][0];
        for(int st=1; st<=2*(n-1); ++st) {
            vector<vector<int>> dpt(n, vector<int> (n, -INF));
            for(int i=max(0, st-(n-1)); i<=min(n-1, st); ++i) {
                for(int j=max(0, st-(n-1)); j<=min(n-1, st); ++j) {
                    if(grid[i][st-i]==-1 || grid[j][st-j]==-1) continue;
                    int here=grid[i][st-i]+(i!=j)*grid[j][st-j];
                    for(int r=i-1; r<=i; ++r) {
                        for(int c=j-1; c<=j; ++c) {
                            if(r<0 || c<0) continue;
                            dpt[i][j]=max(dpt[i][j], here+dp[r][c]);
                        }
                    }
                }
            }
            dp=dpt;
        }
        return max(0, dp[n-1][n-1]);
    }
};
