class Solution {
public:
    int uniquePaths(int m, int n) {
        int steps = m + n - 2;
        int turns = max(m, n) - 1;
        // (s)C(t) = [(s) * (s - 1) * ... * (t + 1)] / [(s - t) * (s - t - 1) * ... * (1)]
        long long ans = 1;
        for (int i = turns + 1; i <= steps; ++i) {
            ans = (ans * i) / (i - turns);
        }
        return ans;
    }
};
