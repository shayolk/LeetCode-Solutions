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
    TreeNode* find(TreeNode* a, TreeNode* b, TreeNode* t) {
        if(a==t) {
            return b;
        }
        if(a->left) {
            TreeNode* l=find(a->left, b->left, t);
            if(l) return l;
        }
        if(a->right) {
            TreeNode* r=find(a->right, b->right, t);
            if(r) return r;
        }
        return NULL;
    }
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return find(original, cloned, target);
    }
};
