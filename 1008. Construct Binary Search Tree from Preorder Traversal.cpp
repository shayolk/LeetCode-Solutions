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
    TreeNode* build(int l, int r, vector<int>& preorder) {
        if(l > r) {
            return NULL;
        }
        int m = l + 1;
        while(m <= r && preorder[m] <= preorder[l]) {
            ++m;
        }
        TreeNode* left = build(l + 1, m - 1, preorder);
        TreeNode* right = build(m, r, preorder);
        TreeNode* node = new TreeNode(preorder[l], left, right);
        return node;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        return build(0, n - 1, preorder);
    }
};
