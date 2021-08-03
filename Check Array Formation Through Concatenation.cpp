class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int n=(int)arr.size(), m=(int)pieces.size();
        vector<int> pos(105,-1);
        for(int i=0; i<n; ++i) {
            pos[arr[i]]=i;
        }
        for(auto v: pieces) {
            for(int i=0; i<(int)v.size(); ++i) {
                if(pos[v[i]]==-1) {
                    return false;
                }
                if(i && pos[v[i]]!=pos[v[i-1]]+1) {
                    return false;
                }
            }
        }
        return true;
    }
};
