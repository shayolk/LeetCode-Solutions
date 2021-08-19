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
    const int M=1e9+7;
    long long sum, ans=0;
    map<TreeNode*, long long> mp;
    
    long long treeSum(TreeNode* root) {
        if(!root) return 0;
        // if(!mp.count(root)) mp[root]=(root->val + (treeSum(root->left) + treeSum(root->right))%M)%M;
        if(!mp.count(root)) mp[root]=root->val + treeSum(root->left) + treeSum(root->right);
        return mp[root];
    }
    
    void find(TreeNode* root) {
        if(!root) return;
        int tot=mp[root];
        // ans=max(ans, (((sum-mp[root]+M)%M) * mp[root])%M);
        ans=max(ans, (sum-mp[root]) * mp[root]);
        find(root->left);
        find(root->right);
    }
        
public:
    int maxProduct(TreeNode* root) {
        sum=treeSum(root);
        find(root);
        return ans%M;
    }
};
