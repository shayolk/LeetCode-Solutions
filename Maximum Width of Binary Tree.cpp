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
    const long long M=2LL+INT_MAX;
    
public:
    int widthOfBinaryTree(TreeNode* root) {
        map<int,long long> left, right;
        queue<pair<TreeNode*,pair<long long,int>>> q;
        q.push({root, {1, 0}});
        while(!q.empty()) {
            pair<TreeNode*,pair<long long,int>> p=q.front();
            q.pop();
            TreeNode* t=p.first;
            long long val=p.second.first;
            int dep=p.second.second;
            if(!t) continue;
            if(left.count(dep)) left[dep]=min(left[dep], val);
            else left[dep]=val;
            if(right.count(dep)) right[dep]=max(right[dep], val);
            else right[dep]=val;
            q.push({t->left, {(2*val)%M, dep+1}});
            q.push({t->right, {((2*val)%M+1)%M, dep+1}});
        }
        long long ans=0;
        for(auto d: left) {
            ans=max(ans, ((right[d.first]-d.second+M)%M+1)%M);
        }
        return (int)ans;
    }
};
