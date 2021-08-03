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
    bool check(TreeNode* t, const vector<int> v, int i) {
        cout<<i<<" "<<t->val<<endl;
        if(!t || i>=n)
            return false;
        if(i == n-1)
            return t->val == v[i] and t->left==NULL and t->right==NULL;
        if(t->val != v[i])
            return false;
        bool l,r;
        if(t->left && t->left->val == v[i+1])
            l = check(t->left, v, i+1);
        if(t->right && t->right->val == v[i+1])
            r = check(t->right, v, i+1);
        return l or r;
    }
public:
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        n = arr.size();
        return check(root, arr, 0);
    }
};
