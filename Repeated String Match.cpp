class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int cnt=1;
        string s=a;
        while(s.size()<b.size()) {
            ++cnt;
            s+=a;
        }
        if(s.find(b)!=string::npos) return cnt;
        ++cnt;
        s+=a;
        if(s.find(b)!=string::npos) return cnt;
        return -1;
    }
};
