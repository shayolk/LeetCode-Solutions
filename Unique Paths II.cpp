class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(), n=obstacleGrid[0].size();
        if(obstacleGrid[0][0]) return 0;
        obstacleGrid[0][0]=1;
        for(int i=1; i<m; ++i) {
            if(obstacleGrid[i][0]) {
                for(int k=i; k<m; ++k) {
                    obstacleGrid[k][0]=0;
                }
                break;
            }
            obstacleGrid[i][0]=1;
        }
        for(int j=1; j<n; ++j) {
            if(obstacleGrid[0][j]) {
                for(int k=j; k<n; ++k) {
                    obstacleGrid[0][k]=0;
                }
                break;
            }
            obstacleGrid[0][j]=1;
        }
        for(int i=1; i<m; ++i) {
            for(int j=1; j<n; ++j) {
                if(obstacleGrid[i][j]) {
                    obstacleGrid[i][j]=0;
                    continue;
                }
                obstacleGrid[i][j]=obstacleGrid[i-1][j]+obstacleGrid[i][j-1];
            }
        }
        return obstacleGrid[m-1][n-1];
    }
};
