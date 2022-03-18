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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int order=0;
        vector<int> now;
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            queue<TreeNode*> tmp;
            now.clear();
            while(!q.empty()) {
                TreeNode* t=q.front();
                q.pop();
                if(!t) continue;
                now.push_back(t->val);
                tmp.push(t->left);
                tmp.push(t->right);
            }
            if(order) reverse(now.begin(), now.end());
            if(!now.empty()) ans.push_back(now);
            order^=1;
            q=tmp;
        }
        return ans;
    }
};
