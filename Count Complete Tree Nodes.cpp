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
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int left=0, right=0;
        TreeNode* t=root;
        while(t) {
            ++left;
            t=t->left;
        }
        t=root;
        while(t) {
            ++right;
            t=t->right;
        }
        if(left==right) return (1<<left)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};
