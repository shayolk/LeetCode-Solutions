/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    pair<vector<Node*>,vector<Node*>> run(Node* root) {
        if(!root || (!root->left && !root->right)) return {{root}, {root}};
        pair<vector<Node*>,vector<Node*>> l=run(root->left), r=run(root->right);
        assert(l.second.size()==r.first.size());
        int n=l.second.size();
        for(int i=0; i<n; ++i) {
            l.second[i]->next=r.first[i];
        }
        l.first.push_back(root);
        r.second.push_back(root);
        return {l.first, r.second};
        
    }
    
public:
    Node* connect(Node* root) {
        run(root);
        return root;
    }
};
