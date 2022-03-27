/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    map<Node*,Node*> mp;
    map<Node*,bool> vis;
    
    void dfs(Node* now) {
        vis[now]=true;
        Node* t=new Node(now->val);
        mp[now]=t;
        for(Node* neb: now->neighbors) {
            if(!vis[neb]) {
                dfs(neb);
            }
        }
        for(Node* neb: now->neighbors) {
            t->neighbors.push_back(mp[neb]);
        }
    }
    
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        dfs(node);
        return mp[node];
    }
};
