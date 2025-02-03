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
    int ans;

    struct Stat {
        bool ok;
        long long mnm;
        long long mxm;
        int sum;

        Stat(bool ok = true, long long mnm = LLONG_MAX, long long mxm = LLONG_MIN, int sum = 0) {
            this->ok = ok;
            this->mnm = mnm;
            this->mxm = mxm;
            this->sum = sum;
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
        int sum = root->val + left.sum + right.sum;
        if(ok) {
            ans = max(ans, sum);
        }
        return Stat(ok, mnm, mxm, sum);
    }

public:
    int maxSumBST(TreeNode* root) {
        ans = 0;
        isValid(root);
        return ans;
    }
};
