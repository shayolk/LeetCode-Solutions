/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    TreeNode* construct(int l, int r, vector<int>& nums) {
        if(l > r) {
            return NULL;
        }
        int m = l + (r - l) / 2;
        TreeNode* left = construct(l, m - 1, nums);
        TreeNode* right = construct(m + 1, r, nums);
        TreeNode* node = new TreeNode(nums[m], left, right);
        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return construct(0, n - 1, nums);
    }
};
