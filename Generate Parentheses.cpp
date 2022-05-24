class Solution {
    vector<string> ans;
    
    void gen(int open, int close, int n, string s) {
        if(close==n) {
            ans.push_back(s);
            return;
        }
        if(open>close) {
            gen(open, close+1, n, s+')');
            if(open==n) return;
        }
        gen(open+1, close, n, s+'(');
    }
    
public:
    vector<string> generateParenthesis(int n) {
        gen(0, 0, n, "");
        return ans;
    }
};
