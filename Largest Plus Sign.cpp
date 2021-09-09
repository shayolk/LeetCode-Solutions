class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> a(n, vector<int> (n, 1));
        for(auto v: mines) {
            a[v[0]][v[1]]=0;
        }
        vector<vector<int>> left=a, right=a, top=a, down=a;
        for(int i=1; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                if(a[i][j]) {
                    top[i][j]+=top[i-1][j];
                }
            }
        }
        for(int i=n-2; i>=0; --i) {
            for(int j=0; j<n; ++j) {
                if(a[i][j]) {
                    down[i][j]+=down[i+1][j];
                }
            }
        }
        for(int j=1; j<n; ++j) {
            for(int i=0; i<n; ++i) {
                if(a[i][j]) {
                    left[i][j]+=left[i][j-1];
                }
            }
        }
        for(int j=n-2; j>=0; --j) {
            for(int i=0; i<n; ++i) {
                if(a[i][j]) {
                    right[i][j]+=right[i][j+1];
                }
            }
        }
        int ans=0;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                if(a[i][j]) {
                    ans=max(ans, min({top[i][j], down[i][j], left[i][j], right[i][j]}));
                }
            }
        }
        return ans;
    }
};
