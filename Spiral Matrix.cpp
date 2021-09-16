class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n=matrix.size(), m=matrix[0].size();
        int i=0, j=-1, dir=0, horl=0, horr=m-1, verl=0, verr=n-1;
        while(horl<=horr && verl<=verr) {
            if(dir==0) {
                ++j;
                while(j<=horr) ans.push_back(matrix[i][j++]);
                --j;
                ++verl;
            }
            else if(dir==1) {
                ++i;
                while(i<=verr) ans.push_back(matrix[i++][j]);
                --i;
                --horr;
            }
            else if(dir==2) {
                --j;
                while(j>=horl) ans.push_back(matrix[i][j--]);
                ++j;
                --verr;
            }
            else {
                --i;
                while(i>=verl) ans.push_back(matrix[i--][j]);
                ++i;
                ++horl;
            }
            dir=(dir+1)%4;
        }
        return ans;
    }
};
