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
    vector<int> in;
    
    void inorder(TreeNode* root) {
        if(!root) return;
        inorder(root->left);
        in.push_back(root->val);
        inorder(root->right);
    }
    
public:
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        int l=0, r=in.size()-1;
        while(l<r) {
            if(in[l]+in[r]==k) {
                return true;
            }
            if(in[l]+in[r]<k) {
                ++l;
            }
            else {
                --r;
            }
        }
        return false;
    }
};
