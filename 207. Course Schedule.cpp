class Solution {
    vector<vector<int>> adj_list;
    vector<bool> vis, on_stack;

    bool dfs(int now) {
        vis[now] = true;
        on_stack[now] = true;
        for(int neb: adj_list[now]) {
            if(!vis[neb] && !dfs(neb)) {
                return false;
            }
            if(on_stack[neb]) {
                return false;
            }
        }
        on_stack[now] = false;
        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adj_list.resize(numCourses);
        vis.resize(numCourses);
        on_stack.resize(numCourses);
        for(vector<int> prerequisite: prerequisites) {
            int before = prerequisite[1];
            int after = prerequisite[0];
            adj_list[before].push_back(after);
        }
        for(int i = 0; i < numCourses; ++i) {
            if(!vis[i] && !dfs(i)) {
                return false;
            }
        }
        return true;
    }
};
