class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int l = 0, r = n - 1, mid;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (target < matrix[mid][0]) {
                r = mid - 1;
            } else if (target > matrix[mid][m - 1]) {
                l = mid + 1;
            } else {
                break;
            }
        }
        if (mid <0 || mid > n) {
            return false;
        }
        int row = mid;
        l = 0, r = m - 1;
        while(l <= r) {
            mid = l + (r - l) / 2;
            if (target < matrix[row][mid]) {
                r = mid - 1;
            } else if (target > matrix[row][mid]) {
                l = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
