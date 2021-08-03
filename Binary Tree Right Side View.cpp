/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root)
            return ans;
        queue<pair<TreeNode*,int>> q;
        unordered_map<int,int> m;
        q.push({root,0});
        while(!q.empty()) {
            pair<TreeNode*,int> p=q.front();
            q.pop();
            TreeNode* t=p.first;
            int lev=p.second;
            if(!m[lev]) {
                ans.emplace_back(t->val);
                m[lev]=1;
            }
            if(t->right)
                q.push({t->right,lev+1});
            if(t->left)
                q.push({t->left,lev+1});
        }
        return ans;
    }
};
