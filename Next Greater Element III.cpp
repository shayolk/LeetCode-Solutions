class Solution {
public:
    int nextGreaterElement(int n) {
        string s=to_string(n);
        next_permutation(s.begin(), s.end());
        int ans=stol(s);
        if(ans<=n || to_string(ans).size()!=s.size()) return -1;
        return ans;
    }
};
