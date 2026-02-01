class Solution {
public:
    void merge(vector<int>& nums1, int n1, vector<int>& nums2, int n2) {
        int n = n1 + n2;
        int i = n - 1;
        int i1 = n1 - 1;
        int i2 = n2 - 1;
        while (i1 >= 0 || i2 >= 0) {
            if (i1 < 0) {
                nums1[i--] = nums2[i2--];
            } else if (i2 < 0) {
                nums1[i--] = nums1[i1--];
            }
            else if (nums1[i1] >= nums2[i2]) {
                nums1[i--] = nums1[i1--];
            } else {
                nums1[i--] = nums2[i2--];
            }
        }
    }
};
