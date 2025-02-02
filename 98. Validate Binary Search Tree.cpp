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
    struct Stat {
        bool ok;
        long long mnm;
        long long mxm;

        Stat(bool ok = true, long long mnm = LLONG_MAX, long long mxm = LLONG_MIN) {
            this->ok = ok;
            this->mnm = mnm;
            this->mxm = mxm;
        }
    };

    Stat isValid(TreeNode* root) {
        if(!root) {
            return Stat();
        }
        Stat left = isValid(root->left);
        Stat right = isValid(root->right);
        bool child = left.ok && right.ok;
        bool ok = child && left.mxm < root->val && root->val < right.mnm;
        long long mnm = min({1ll * root->val, left.mnm, right.mnm});
        long long mxm = max({1ll * root->val, left.mxm, right.mxm});
        return Stat(ok, mnm, mxm);
    }

public:
    bool isValidBST(TreeNode* root) {
        return isValid(root).ok;
    }
};
