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
    const int INF=1e9+5;
    int ans=0;
    
    pair<bool,vector<int>> check(TreeNode* root) {
        if(!root) return {true, {0, INF, -INF}};
        pair<bool,vector<int>> l=check(root->left), r=check(root->right);
        bool here=l.second[2]<root->val && root->val<r.second[1] && l.first && r.first;
        int sum=l.second[0]+root->val+r.second[0];
        if(here) ans=max(ans, sum);
        int mn=min(root->val, l.second[1]), mx=max(root->val, r.second[2]);
        return {here, {sum, mn, mx}};
    }
    
public:
    int maxSumBST(TreeNode* root) {
        check(root);
        return ans;
    }
};
