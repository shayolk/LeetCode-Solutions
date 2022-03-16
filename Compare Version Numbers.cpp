class Solution {
    vector<int> convert(string& s) {
        vector<int> ret;
        string now;
        for(char c: s) {
            if(c=='.') {
                ret.push_back(stoi(now));
                now.clear();
            }
            else {
                now+=c;
            }
        }
        ret.push_back(stoi(now));
        return ret;
    }
    
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1=convert(version1), v2=convert(version2);
        int n=v1.size(), m=v2.size();
        for(int i=0; i<min(n, m); ++i) {
            if(v1[i]>v2[i]) return 1;
            else if(v1[i]<v2[i]) return -1;
        }
        for(int i=min(n, m); i<n; ++i) {
            if(v1[i]) return 1;
        }
        for(int i=min(n, m); i<m; ++i) {
            if(v2[i]) return -1;
        }
        return 0;
    }
};
