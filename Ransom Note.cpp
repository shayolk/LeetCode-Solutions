class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> v(26);
        for(char x: magazine) {
            ++v[x-'a'];
        }
        for(char x: ransomNote) {
            if(v[x-'a']<1) {
                return false;
            }
            --v[x-'a'];
        }
        return true;
    }
};
