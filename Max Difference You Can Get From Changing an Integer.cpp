class Solution {
public:
    int maxDiff(int num) {
        if(num/10==0)
            return 8;
        string s;
        map<char,vector<int>> m;
        while(num) {
            s=(char)('0'+num%10)+s;
            num/=10;
        }
        int n=s.size();
        for(int i=0; i<n; ++i)
            m[s[i]].push_back(i);
        string s1=s, s2=s;
        if(s[0]=='9') {
            char c;
            for(char j: s)
                if(j!='9') {
                    c=j;
                    break;
                }
            for(int i: m[c])
                s1[i]='9';
        }
        else
            for(int i: m[s[0]])
                s1[i]='9';
        if(s[0]=='1') {
            char c;
            for(char i: s)
                if(i!='1' && i!='0') {
                    c=i;
                    break;
                }
            for(int i: m[c])
                if(i)
                    s2[i]='0';
        }
        else
            for(int i: m[s[0]])
                s2[i]='1';
        int a=0, b=0;
        for(int i=0; i<n; ++i) {
            a=a*10+(int)(s1[i]-'0');
            b=b*10+(int)(s2[i]-'0');
        }
        return a-b;
    }
};
