class Solution {
public:
    bool checkValidString(string s) {
        int n=s.length();
        int up=0, down=0;
        for(int i=0; i<n; ++i) {
            if(s[i]=='*' || s[i]=='(')  ++up;
            else --up;
            if(s[n-1-i]=='*' || s[n-1-i]==')')  ++down;
            else --down;
            if(up<0 || down<0)  return false;
        }
        return true;
        
        /*int depth=0, min=0, max=0, star=0;
        for(char x: s) {
            if(x=='(') {
                ++depth;
                ++min;
                ++max;
            }
            else if(x==')') {
                --depth;
                --min;
                --max;
            }
            else {
                ++max;
                --min;
                star=1;
            }
            if(max<0) {
                return false;
            }
            if(min<0) {
                min=0;
            }
        }
        return min==0;*/
    }
};
