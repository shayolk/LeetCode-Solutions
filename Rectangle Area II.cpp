class Solution {
    const int M=1e9+7;
    
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        set<long long> xcord, ycord;
        for(auto v: rectangles) {
            xcord.insert(v[0]);
            ycord.insert(v[1]);
            xcord.insert(v[2]);
            ycord.insert(v[3]);
        }
        vector<long long> imx(xcord.begin(), xcord.end()), imy(ycord.begin(), ycord.end());
        map<long long,int> mx, my;
        int n=imx.size(), m=imy.size();
        for(int i=0; i<n; ++i) {
            mx[imx[i]]=i;
        }
        for(int i=0; i<m; ++i) {
            my[imy[i]]=i;
        }
        vector<vector<bool>> grid(n, vector<bool> (m));
        for(auto v: rectangles) {
            for(int i=mx[v[0]]; i<mx[v[2]]; ++i) {
                for(int j=my[v[1]]; j<my[v[3]]; ++j) {
                    grid[i][j]=true;
                }
            }
        }
        long long ans=0;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(grid[i][j]) {
                    long long x=(imx[i+1]-imx[i]+M)%M;
                    long long y=(imy[j+1]-imy[j]+M)%M;
                    ans=(ans+(x*y)%M)%M;
                }
            }
        }
        return (int)ans;
    }
};
