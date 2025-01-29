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
    long long M = 1e18 + 7;
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) {
            return 0;
        }
        queue<pair<TreeNode*,long long>> q;
        q.push({root, 1});
        long long width = 1;
        while(!q.empty()) {
            int length = q.size();
            long long left = q.front().second;
            long long right = q.back().second;
            width = max(width, ((right - left + M) % M + 1) % M);
            while(length--) {
                auto now = q.front();
                q.pop();
                if(now.first->left) {
                    q.push({now.first->left, (2 * now.second) % M});
                }
                if(now.first->right) {
                    q.push({now.first->right, ((2 * now.second) % M + 1) % M});
                }
            }
        }
        return (int)width;
    }
};
