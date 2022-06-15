class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();
        for(int off=0; off<m; ++off) {
            for(int i=1; i<n && i+off<m; ++i) {
                if(matrix[i][i+off]!=matrix[0][off]) {
                    return false;
                }
            }
        }
        for(int off=0; off<n; ++off) {
            for(int i=1; i+off<n && i<m; ++i) {
                if(matrix[i+off][i]!=matrix[off][0]) {
                    return false;
                }
            }
        }
        return true;
    }
};
