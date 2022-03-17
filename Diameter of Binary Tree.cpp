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
    pair<int,int> diameter(TreeNode* root) {
        if(!root) return {0, 0};
        pair<int,int> l=diameter(root->left), r=diameter(root->right);
        int dia=max({l.first, r.first, l.second+r.second});
        int dep=1+max(l.second, r.second);
        return {dia, dep};
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return diameter(root).first;
    }
};
