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
    TreeNode* build(int l, int r, vector<int>& nums) {
        if(l>r) return NULL;
        int mid=l+(r-l)/2;
        TreeNode* t=new TreeNode(nums[mid]);
        if(l==r) return t;
        t->left=build(l, mid-1, nums);
        t->right=build(mid+1, r, nums);
        return t;
    }
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        return build(0, n-1, nums);
    }
};
