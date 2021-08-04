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
    vector<vector<int>> ans;
    
    void find(TreeNode* root, int targetSum, int sum, vector<int> v) {
        if(!root) {
            return;
        }
        sum+=root->val;
        v.push_back(root->val);
        if(sum==targetSum && !root->left && !root->right) {
            ans.push_back(v);
            return;
        }
        find(root->left, targetSum, sum, v);
        find(root->right, targetSum, sum, v);
    }
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        find(root, targetSum, 0, vector<int>{});
        return ans;
    }
};
