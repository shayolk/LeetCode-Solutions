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
    int n, p;
    map<int,int> pos;
    
    TreeNode* build(vector<int>& pre, vector<int>& in, int l, int r) {
        if(p>=n || l>r) return NULL;
        TreeNode* t=new TreeNode(pre[p++]);
        if(l==r) return t;
        int i=pos[t->val];
        t->left=build(pre, in, l, i-1);
        t->right=build(pre, in, i+1, r);
        return t;
    }
    
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        n=preorder.size();
        vector<int> inorder=preorder;
        sort(inorder.begin(), inorder.end());
        for(int i=0; i<n; ++i) {
            pos[inorder[i]]=i;
        }
        p=0;
        return build(preorder, inorder, 0, n-1);
    }
};
