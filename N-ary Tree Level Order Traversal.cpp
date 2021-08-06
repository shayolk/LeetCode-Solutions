/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        vector<int> now;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        int dep=0;
        while(!q.empty()) {
            pair<Node*, int> at=q.front();
            q.pop();
            Node* t=at.first;
            int d=at.second;
            if(!t) {
                continue;
            }
            if(d!=dep && !now.empty()) {
                ans.push_back(now);
                now.clear();
                ++dep;
            }
            now.push_back(t->val);
            for(Node* child: t->children) {
                q.push({child, d+1});
            }
        }
        if(!now.empty()) {
            ans.push_back(now);
        }
        return ans;
    }
};
