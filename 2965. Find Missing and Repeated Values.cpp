class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int xoor = 0;
        for (int i = 1; i <= n*n; ++i) {
            xoor ^= i;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                xoor ^= grid[i][j];
            }
        }
        int bit = 0;
        while (bit < 31 && !(xoor & 1<<bit)) {
            ++bit;
        }
        int zero = 0, one = 0;
        for (int i = 1; i <= n*n; ++i) {
            if (i & (1 << bit)) {
                    one ^= i;
                } else {
                    zero ^= i;
                }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] & (1 << bit)) {
                    one ^= grid[i][j];
                } else {
                    zero ^= grid[i][j];
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == zero) {
                    ++cnt;
                }
            }
        }
        if (cnt) {
            return {zero, one};
        }
        return {one, zero};
    }
};
