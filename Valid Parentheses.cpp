class Solution {
    map<char,char> par={
        {')', '('},
        {'}', '{'},
        {']', '['}
    };
    
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c: s) {
            if(!par.count(c)) {
                st.push(c);
            }
            else {
                if(st.empty() || st.top()!=par[c]) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
