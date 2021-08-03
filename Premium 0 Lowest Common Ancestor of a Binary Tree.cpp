/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    vector<int> depth;
    vector<TreeNode*> node;
    map<TreeNode*, int> last;
    int tot=0;
    
    void dfs(TreeNode* root, int height) {
        if(!root) {
            return;
        }
        node.push_back(root);
        depth.push_back(height);
        last[root]=tot++;
        
        dfs(root->left, height+1);
        
        node.push_back(root);
        depth.push_back(height);
        last[root]=tot++;
        
        dfs(root->right, height+1);
        
        node.push_back(root);
        depth.push_back(height);
        last[root]=tot++;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || !p || !q) {
            return NULL;
        }
        dfs(root, 0);
        // for(int i=0; i<depth.size(); ++i) cout<<node[i]->val<<" "<<depth[i]<<"\n";
        int lastp=last[p], lastq=last[q];
        int st=min(lastp, lastq), ed=max(lastp, lastq);
        int ind=-1, mn=2e9+5;
        for(int i=st; i<=ed; ++i) {
            if(depth[i]<mn) {
                mn=depth[i];
                ind=i;
            }
        }
        return node[ind];
    }
};
