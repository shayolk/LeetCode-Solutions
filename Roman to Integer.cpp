class Solution {
    map<char,int> val{
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    
public:
    int romanToInt(string s) {
        int n=s.size();
        s+='I';
        int ans=0;
        for(int i=n-1; i>=0; --i) {
            if(val[s[i]]>=val[s[i+1]]) ans+=val[s[i]];
            else ans-=val[s[i]];
        }
        return ans;
    }
};
