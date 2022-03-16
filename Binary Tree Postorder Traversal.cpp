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
        visit(root->right);
        ans.push_back(root->val);
    }
    
public:
    vector<int> postorderTraversal(TreeNode* root) {
        visit(root);
        return ans;
    }
};
