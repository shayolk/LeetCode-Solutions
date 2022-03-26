class Solution {
    int n, m, color, newColor;
    vector<vector<bool>> vis;
    
    const int dr[4]={0, 0, 1, -1};
    const int dc[4]={1, -1, 0, 0};
    
    bool safe(int r, int c, vector<vector<int>>& image) {
        return r>=0 && r<n && c>=0 && c<m && !vis[r][c] && image[r][c]==color;
    }
    
    void dfs(int r, int c, vector<vector<int>>& image) {
        vis[r][c]=true;
        image[r][c]=newColor;
        for(int d=0; d<4; ++d) {
            int rr=r+dr[d], cc=c+dc[d];
            if(!safe(rr, cc, image)) continue;
            dfs(rr, cc, image);
        }
    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        n=image.size();
        m=image[0].size();
        color=image[sr][sc];
        this->newColor=newColor;
        vis.resize(n, vector<bool> (m));
        dfs(sr, sc, image);
        return image;
    }
};
