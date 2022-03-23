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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        int rr=root->val, pp=p->val, qq=q->val;
        if(min(pp, qq)<rr && max(pp, qq)<rr) return lowestCommonAncestor(root->left, p, q);
        if(rr<min(pp, qq) && rr<max(pp, qq)) return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};
