class Solution {
    static constexpr int D = 4;
    static constexpr int dr[D] = {-1,  0,  0, +1};
    static constexpr int dc[D] = { 0, -1, +1,  0};

    int n, m;
    int cnt;

    bool safe(int r, int c, vector<vector<char>>& grid) {
        return r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == '1';
    }

    void dfs(int r, int c, vector<vector<char>>& grid) {
        grid[r][c] = '0';
        for(int d = 0; d < D; ++d) {
            int rr = r + dr[d];
            int cc = c + dc[d];
            if(safe(rr, cc, grid)) {
                dfs(rr, cc, grid);
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        cnt = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid[i][j] == '1') {
                    dfs(i, j, grid);
                    ++cnt;
                }
            }
        }
        return cnt;
    }
};
