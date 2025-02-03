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
    char neg;

    int findHeight(TreeNode* root) {
        if(!root) {
            return 0;
        }
        return 1 + max(findHeight(root->left), findHeight(root->right));
    }

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

    void tree2vector(TreeNode* root, int ind, vector<TreeNode*>& vt) {
        if(!root) {
            return;
        }
        vt[ind] = root;
        tree2vector(root->left, ind * 2, vt);
        tree2vector(root->right, ind * 2 + 1, vt);
    }

    string vector2string(vector<TreeNode*> vt) {
        int n = vt.size();
        string data;
        for(int i = 0; i < n; ++i) {
            if(vt[i]) {
                data += to_string(vt[i]->val);
            }
            else {
                data += null;
            }
            data += del;
        }
        return data;
    }

    vector<TreeNode*> string2vector(string data) {
        vector<TreeNode*> vt;
        vector<string> vs = split(data);
        for(string s: vs) {
            if(s == string(1, null)) {
                vt.push_back(NULL);
            }
            else {
                vt.push_back(new TreeNode(stoi(s)));
            }
        }
        return vt;
    }

    void vector2tree(vector<TreeNode*>& vt, int ind, int& n) {
        if(ind >= n || !vt[ind]) {
            return;
        }
        if(2 * ind < n && vt[ind]) {
            vt[ind]->left = vt[2 * ind];
        }
        if(2 * ind + 1 < n && vt[ind]) {
            vt[ind]->right = vt[2 * ind + 1];
        }
        vector2tree(vt, 2 * ind, n);
        vector2tree(vt, 2 * ind + 1, n);
    }

public:
    Codec() {
        del = '.';
        null = '#';
        neg = '-';
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        int height = findHeight(root);
        int length = 1<<height;
        vector<TreeNode*> vt(length, NULL);
        tree2vector(root, 1, vt);
        string data = vector2string(vt);
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<TreeNode*> vt = string2vector(data);
        int n = vt.size();
        vector2tree(vt, 1, n);
        if(n <= 1) {
            return NULL;
        }
        return vt[1];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
