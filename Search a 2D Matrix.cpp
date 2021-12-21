class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(), m=matrix[0].size();
        int lo=0, hi=n-1, mid, row=0;
        while(lo<=hi) {
            mid=lo+(hi-lo)/2;
            if(matrix[mid][0]==target) {
                return true;
            }
            if(matrix[mid][0]<target) {
                row=max(row, mid);
                lo=mid+1;
            }
            else {
                hi=mid-1;
            }
        }
        lo=0, hi=m-1;
        while(lo<=hi) {
            mid=lo+(hi-lo)/2;
            if(matrix[row][mid]==target) {
                return true;
            }
            if(matrix[row][mid]<target) {
                lo=mid+1;
            }
            else {
                hi=mid-1;
            }
        }
        return false;
    }
};
