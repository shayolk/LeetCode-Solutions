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
    static bool comp(const pair<int,int>& a, const pair<int,int>& b) {
        if(a.second==b.second) return a.first<b.first;
        return a.second<b.second;
    }
    
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>> view;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root, {0, 0}});
        while(!q.empty()) {
            pair<TreeNode*,pair<int,int>> p=q.front();
            q.pop();
            if(!p.first) continue;
            view[p.second.second].push_back({p.first->val, p.second.first});
            q.push({p.first->left, {p.second.first+1, p.second.second-1}});
            q.push({p.first->right, {p.second.first+1, p.second.second+1}});
        }
        vector<vector<int>> ans;
        for(auto& v: view) {
            sort(v.second.begin(), v.second.end(), comp);
            vector<int> here;
            for(auto h: v.second) {
                here.push_back(h.first);
            }
            ans.push_back(here);
        }
        return ans;
    }
};
