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
    pair<int,int> info[101];
    void store(TreeNode *root, int depth, int parent) {
        if(root == NULL) {
            return;
        }
        info[root->val] = {depth, parent};
        store(root->left, depth+1, root->val);
        store(root->right, depth+1, root->val);
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        store(root, 0, -1);
        return info[x].first == info[y].first and info[x].second != info[y].second;
    }
};
