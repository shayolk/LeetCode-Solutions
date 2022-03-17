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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<int> lvl;
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()) {
            TreeNode* now=q.front();
            q.pop();
            if(!now) {
                ans.push_back(lvl);
                lvl.clear();
                if(q.empty()) break;
                q.push(NULL);
                continue;
            }
            lvl.push_back(now->val);
            if(now->left) q.push(now->left);
            if(now->right) q.push(now->right);
        }
        return ans;
    }
};
