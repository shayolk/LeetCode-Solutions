/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    int height(TreeNode* root) {
        if(root==NULL)  return 0;
        return 1+max(height(root->left),height(root->right));
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)   return 0;
        return max({height(root->left)+height(root->right), diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)});
    }
};
