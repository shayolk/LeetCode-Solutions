class Solution {
    string parse(string s) {
        int i=0, n=s.size();
        string res;
        bool flag=true;
        while(i<n && s[i]!='@') {
            if(s[i]=='+') flag=false;
            if(flag && s[i]!='.') res+=s[i];
            ++i;
        }
        res+=s.substr(i, n-i);
        return res;
    }
    
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> ans;
        for(string s: emails) {
            ans.insert(parse(s));
        }
        return (int)ans.size();
    }
};
