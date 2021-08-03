class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, int > m;
        vector<vector<string>> v(strs.size());
        int ind=0;
        for(string i: strs)
        {
            string s=i;
            sort(s.begin(),s.end());
            if(m.find(s)==m.end())  m[s]=ind++;
            v[m[s]].push_back(i);
        }
        v.resize(m.size());
        return v;
    }
};
