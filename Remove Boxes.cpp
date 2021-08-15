class Solution {
    static const int nax=105;
    int dp[nax][nax][nax];
    
    int solve(int l, int r, int k, vector<int>& boxes) {
        if(l>r) return 0;
        if(dp[l][r][k]!=-1) return dp[l][r][k];
        dp[l][r][k]=(k+1)*(k+1)+solve(l+1, r, 0, boxes);
        for(int m=l; m<r; ++m) {
            if(boxes[m+1]==boxes[l]) {
                dp[l][r][k]=max(dp[l][r][k], solve(l+1, m, 0, boxes)+solve(m+1, r, k+1, boxes));
            }
        }
        return dp[l][r][k];
    }
        
public:
    int removeBoxes(vector<int>& boxes) {
        memset(dp, -1, sizeof(dp));
        return solve(0, boxes.size()-1, 0, boxes);
    }
};
