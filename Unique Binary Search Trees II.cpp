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
    map<pair<int,int>,vector<TreeNode*>> dp;
    
    vector<TreeNode*> gen(int st, int ed) {
        if(st>ed) return {NULL};
        if(dp.count({st, ed})) return dp[{st, ed}];
        vector<TreeNode*> roots;
        for(int root=st; root<=ed; ++root) {
            vector<TreeNode*> left=gen(st, root-1), right=gen(root+1, ed);
            for(auto l: left) {
                for(auto r: right) {
                    roots.push_back(new TreeNode(root, l, r));
                }
            }
        }
        return dp[{st, ed}]=roots;
    }
    
public:
    vector<TreeNode*> generateTrees(int n) {
        return gen(1, n);
    }
};
