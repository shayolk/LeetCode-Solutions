class Solution {
    int count(vector<int>& nums, int l, int m, int r) {
        int i = l, j = m + 1;
        int cnt = 0;
        while (i <= m) {
            while (j <= r && nums[i] > 2ll * nums[j]) {
                ++j;
            }
            cnt += j - m - 1;
            ++i;
        }
        return cnt;
    }

    int merge(vector<int>& nums, int l, int r) {
        if (l >= r) {
            return 0;
        }
        int m = l + (r - l) / 2;
        int left = merge(nums, l, m);
        int right = merge(nums, m + 1, r);
        int here = count(nums, l, m, r);
        vector<int> temp;
        int i = l, j = m + 1;
        while (i <= m && j <= r) {
            if (nums[i] < nums[j]) {
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[j++]);
            }
        }
        while (i <= m) {
            temp.push_back(nums[i++]);
        }
        while (j <= r) {
            temp.push_back(nums[j++]);
        }
        for (int k = l; k <= r; ++k) {
            nums[k] = temp[k - l];
        }
        return left + here + right;
    }

public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return merge(nums, 0, n - 1);
    }
};
