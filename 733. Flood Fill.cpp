class Solution {
    static constexpr int dr[4] = {-1,  0,  0, +1};
    static constexpr int dc[4] = { 0, -1, +1,  0};

    int n, m, org;
    vector<vector<bool>> vis;

    bool safe(int r, int c, vector<vector<int>>& image) {
        return r >= 0 && r < n && c >= 0 && c < m && !vis[r][c] && image[r][c] == org;
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n = image.size();
        m = image[0].size();
        org = image[sr][sc];
        vis.resize(n, vector<bool> (m));
        queue<pair<int,int>> q;
        q.push({sr, sc});
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            vis[r][c] = true;
            image[r][c] = color;
            for(int d = 0; d < 4; ++d) {
                int rr = r + dr[d];
                int cc = c + dc[d];
                if(!safe(rr, cc, image)) {
                    continue;
                }
                q.push({rr, cc});
            }
        }
        return image;
    }
};
