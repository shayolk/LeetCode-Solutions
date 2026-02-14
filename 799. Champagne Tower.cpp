class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> dp(query_row + 3);
        dp[1] = 1.0 * poured;
        for (int row = 2; row <= query_row + 1; ++ row) {
            for(int col = row + 1; col >= 1; --col) {
                dp[col] = max(0.0, (dp[col] - 1.0) / 2.0);
                dp[col] += max(0.0, (dp[col - 1] - 1.0) / 2.0);
            }
        }
        return min(1.0, dp[query_glass + 1]);
    }
};
