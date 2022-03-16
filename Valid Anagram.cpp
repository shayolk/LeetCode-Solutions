class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> cnt(26);
        for(char c: s) {
            ++cnt[c-'a'];
        }
        for(char c: t) {
            --cnt[c-'a'];
        }
        for(int c: cnt) {
            if(c) return false;
        }
        return true;
    }
};
