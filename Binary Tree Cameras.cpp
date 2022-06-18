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
    
    vector<int> cam(TreeNode* root) {
        if(!root) return {0, 0, INF};
        vector<int> l=cam(root->left), r=cam(root->right);
        vector<int> ret(3);
        ret[0]=l[1]+r[1];
        ret[1]=min(l[2]+min(r[1], r[2]), min(l[1], l[2])+r[2]);
        ret[2]=1+min({l[0], l[1], l[2]})+min({r[0], r[1], r[2]});
        return ret;
    }
    
public:
    int minCameraCover(TreeNode* root) {
        vector<int>ans=cam(root);
        return min(ans[1], ans[2]);
    }
};
