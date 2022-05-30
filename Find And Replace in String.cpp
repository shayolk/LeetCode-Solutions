class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int n=indices.size();
        vector<pair<int,int>> ind;
        for(int i=0; i<n; ++i) {
            ind.push_back({indices[i], i});
        }
        sort(ind.rbegin(), ind.rend());
        for(int j=0; j<n; ++j) {
            int i=ind[j].second;
            if(s.substr(indices[i], sources[i].size())==sources[i]) {
                s=s.substr(0, indices[i])+targets[i]+s.substr(indices[i]+sources[i].size());
            }
        }
        return s;
    }
};
