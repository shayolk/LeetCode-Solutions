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
    const long long INF=1e18+5;
    
    pair<bool,pair<long long,long long>> check(TreeNode* root) {
        if(!root) return {true, {INF, -INF}};
        pair<bool,pair<long long,long long>> l=check(root->left), r=check(root->right);
        long long data=1ll*root->val;
        bool here=l.first && r.first && data>l.second.second && data<r.second.first;
        long long lmin=min(data, l.second.first), rmax=max(data, r.second.second);
        return {here, {lmin, rmax}};
    }
    
public:
    bool isValidBST(TreeNode* root) {
        return check(root).first;
    }
};
