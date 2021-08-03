class Solution {
    int n, m, newCol;
    pair<int,int> dir[4] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    set<pair<int,int>> done;
    bool check(int row, int col) {
        return row >= 0 and row < n and col >=0 and col < m;
    }
    void dfs(vector<vector<int>>& image, int row, int col, int color) {
        image[row][col] = newCol;
        for(int i = 0; i < 4; ++i) {
            if(check(row + dir[i].first, col + dir[i].second) && image[row + dir[i].first][col + dir[i].second] == color && done.find({row + dir[i].first, col + dir[i].second}) == done.end()) {
                done.insert({row + dir[i].first, col + dir[i].second});
                dfs(image, row + dir[i].first, col + dir[i].second, color);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        n = image.size();
        m = image[0].size();
        newCol = newColor;
        dfs(image, sr, sc, image[sr][sc]);
        return image;
    }
};
