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
class BSTIterator {
    stack<TreeNode*> s;
    
    void add(TreeNode* root) {
        if(!root) return;
        while(root) {
            s.push(root);
            root=root->left;
        }
    }
    
public:
    BSTIterator(TreeNode* root) {
        add(root);
    }
    
    int next() {
        if(!hasNext()) return -1;
        TreeNode* t=s.top();
        s.pop();
        add(t->right);
        return t->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
