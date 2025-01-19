class Solution {
    map<char,char> mp;

public:
    Solution() {
        mp[')'] = '(';
        mp['}'] = '{';
        mp[']'] = '[';
    }

    bool isValid(string s) {
        stack<char> st;
        for(char c: s) {
            if(!st.empty() && st.top() == mp[c]) {
                st.pop();
            }
            else {
                st.push(c);
            }
        }
        return st.empty();
    }
};
