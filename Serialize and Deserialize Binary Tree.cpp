/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    const int dum=1111;
    
    queue<int> convert(string s) {
        queue<int> res;
        string now;
        for(char c: s) {
            if(c=='*') {
                if(now=="#") res.push(dum);
                else res.push(stoi(now));
                now.clear();
            }
            else {
                now+=string(1, c);
            }
        }
        return res;
    }
    
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* t=q.front();
            q.pop();
            if(!t) {
                ans+="#*";
                continue;
            }
            ans+=to_string(t->val)+"*";
            q.push(t->left);
            q.push(t->right);
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;
        queue<int> d=convert(data);
        TreeNode* root=new TreeNode(d.front());
        d.pop();
        queue<TreeNode*> q;
        q.push(root);
        while(!d.empty()) {
            TreeNode* t=q.front();
            q.pop();
            if(d.front()!=dum) {
                t->left=new TreeNode(d.front());
                q.push(t->left);
            }
            d.pop();
            if(d.front()!=dum) {
                t->right=new TreeNode(d.front());
                q.push(t->right);
            }
            d.pop();
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
