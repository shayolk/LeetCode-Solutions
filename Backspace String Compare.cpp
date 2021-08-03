class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack <char> a,b;
        for(char i: S)  
        {
            if(i=='#')
            {
                if(!a.empty())  a.pop();
            }
            else    a.push(i);
        }
        for(char i: T)  
        {
            if(i=='#')  
            {
                if(!b.empty())  b.pop();
            }
            else    b.push(i);
        }
        return a==b;
    }
};
