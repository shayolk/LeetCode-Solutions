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
    stack<TreeNode*> stn, stp;

    void addNext(TreeNode* root) {
        while(root) {
            stn.push(root);
            root = root->left;
        }
    }

    void addPrev(TreeNode* root) {
        while(root) {
            stp.push(root);
            root = root->right;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        addNext(root);
        addPrev(root);
    }
    
    TreeNode* next() {
        if(!hasNext()) {
            return NULL;
        }
        TreeNode* top = stn.top();
        stn.pop();
        addNext(top->right);
        return top;
    }
    
    bool hasNext() {
        return !stn.empty();
    }
    
    TreeNode* prev() {
        if(!hasPrev()) {
            return NULL;
        }
        TreeNode* top = stp.top();
        stp.pop();
        addPrev(top->left);
        return top;
    }
    
    bool hasPrev() {
        return !stp.empty();
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator it = BSTIterator(root);
        TreeNode *l = it.next(), *r = it.prev();
        while(l && r && l != r) {
            if(l->val + r->val == k) {
                return true;
            }
            if(l->val + r->val < k) {
                l = it.next();
            }
            else {
                r = it.prev();
            }
        }
        return false;
    }
};
