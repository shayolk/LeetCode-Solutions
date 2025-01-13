class Solution {
public:
    int minimumLength(string s) {
        vector<int> count(26);
        for(char c: s) {
            ++count[c - 'a'];
        }
        int ans = 0;
        for(int c: count) {
            if(!c) {
                continue;
            }
            ans += (c + 1) % 2 + 1;
        }
        return ans;
    }
};
