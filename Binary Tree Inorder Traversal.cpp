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
    vector<int> ans;
    
    void visit(TreeNode* root) {
        if(!root) return;
        visit(root->left);
        ans.push_back(root->val);
        visit(root->right);
    }
    
public:
    vector<int> inorderTraversal(TreeNode* root) {
        visit(root);
        return ans;
    }
};
