class Solution {
public:
    string longestPalindrome(string s) {
        if(!s.size())     return "";
        int st=0, ed=0;
        for(int i=0; i<s.size(); ++i)
        {
            int len=max(pal(s,i,i), pal(s,i,i+1));
            if(len>ed-st)
            {
                st=i-(len-1)/2;
                ed=i+len/2;
            }
        }
        return s.substr(st,ed-st+1);
    }
    
    int pal(string s, int l, int r)
    {
        int len=0;
        while(l>=0 && r<s.size())
        {
            if(s[l]==s[r])
            {
                len=r-l+1;
                --l;
                ++r;
            }
            else    break;
        }
        return len;
    }
};
