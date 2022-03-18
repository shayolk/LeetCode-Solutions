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
    
    pair<int,int> find(TreeNode* root) {
        if(!root) return {-INF, 0};
        pair<int,int> l=find(root->left), r=find(root->right);
        int ans=max({l.first, r.first, l.second+root->val+r.second});
        int sum=max(0, root->val+max(l.second, r.second));
        return {ans, sum};
    }
public:
    int maxPathSum(TreeNode* root) {
        return find(root).first;
    }
};
