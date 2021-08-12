class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        map<string,vector<string>> m;
        for(string s: strs) {
            string d=s;
            sort(d.begin(), d.end());
            m[d].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto [s, v]: m) {
            ans.push_back(v);
        }
        return ans;
    }
};
