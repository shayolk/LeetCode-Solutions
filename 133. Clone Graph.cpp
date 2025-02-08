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
    map<Node*,Node*> clone;

    void dfs(Node* now) {
        if(!now) {
            return;
        }
        Node* tmp = new Node(now->val);
        clone[now] = tmp;
        for(Node* neb: now->neighbors) {
            if(!clone.count(neb)) {
                dfs(neb);
            }
        }
        for(Node* neb: now->neighbors) {
            tmp->neighbors.push_back(clone[neb]);
        }
    }

public:
    Node* cloneGraph(Node* node) {
        dfs(node);
        return clone[node];
    }
};
