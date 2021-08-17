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
    int find(TreeNode* root, int mx) {
        if(!root) return 0;
        int ans=(root->val)>=mx;
        mx=max(mx, root->val);
        return ans+find(root->left, mx)+find(root->right, mx);
    }
    
public:
    int goodNodes(TreeNode* root) {
        return find(root, -1e9-5);
    }
};
