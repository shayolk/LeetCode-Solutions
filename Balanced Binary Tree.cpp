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
    pair<bool,int> find(TreeNode* root) {
        if(!root) return {true, 0};
        pair<bool,int> l=find(root->left), r=find(root->right);
        bool here=l.first && r.first && abs(l.second-r.second)<=1;
        int depth=1+max(l.second, r.second);
        return {here, depth};
    }
    
public:
    bool isBalanced(TreeNode* root) {
        return find(root).first;
    }
};
