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
    char del;
    char null;
    char end;

    vector<string> split(string data) {
        vector<string> vs;
        string now = "";
        for(char c: data) {
            if(c == del) {
                vs.push_back(now);
                now = "";
            }
            else {
                now += c;
            }
        }
        return vs;
    }

    TreeNode* getNode(string s) {
        if(s == string(1, null)) {
            return NULL;
        }
        return new TreeNode(stoi(s));
    }

public:
    Codec() {
        del = '.';
        null = '*';
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data;
        if(!root) {
            return data;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int length = q.size();
            string here;
            bool cont = false;
            while(length--) {
                TreeNode* node = q.front();
                q.pop();
                if(!node) {
                    here += null;
                    here += del;
                    continue;
                }
                cont = true;
                here += to_string(node->val);
                here += del;
                q.push(node->left);
                q.push(node->right);
            }
            if(!cont) {
                break;
            }
            data += here;
        }
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vs = split(data);
        int n = vs.size();
        if(!n) {
            return NULL;
        }
        int i = 0;
        queue<TreeNode*> q;
        TreeNode* root = getNode(vs[i++]);
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if(i < n) {
                TreeNode* left = getNode(vs[i++]);
                node->left = left;
                if(left) {
                    q.push(left);
                }
            }
            if(i < n) {
                TreeNode* right = getNode(vs[i++]);
                node->right = right;
                if(right) {
                    q.push(right);
                }
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
