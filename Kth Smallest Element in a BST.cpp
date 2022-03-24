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
    int ans;
    
    void find(TreeNode* root, int& k, bool& done) {
        if(!root || done) return;
        find(root->left, k, done);
        --k;
        if(k==0) {
            ans=root->val;
            done=true;
            return;
        }
        find(root->right, k, done);
    }
    
public:
    int kthSmallest(TreeNode* root, int k) {
        bool done=false;
        find(root, k, done);
        return ans;
    }
};
