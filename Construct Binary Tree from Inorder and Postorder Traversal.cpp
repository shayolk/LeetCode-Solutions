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
    int n;
    map<int,int> pos;
    
    TreeNode* build(vector<int>& post, vector<int>& in, int& p, int l, int r) {
        if(p<0 || l>r) return NULL;
        TreeNode* t=new TreeNode(post[p--]);
        if(l==r) return t;
        int i=pos[t->val];
        t->right=build(post, in, p, i+1, r);
        t->left=build(post, in, p, l, i-1);
        return t;
    }
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        n=postorder.size();
        for(int i=0; i<n; ++i) {
            pos[inorder[i]]=i;
        }
        int p=n-1;
        return build(postorder, inorder, p, 0, n-1);
    }
};
