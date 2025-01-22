class Solution {
    void removeWitespace(string& s) {
        while(!s.empty() && s.back() == ' ') {
            s.pop_back();
        }
        int n = s.size();
        int l = 0, r = 0;
        while(l < n && r < n) {
            while(r < n && s[r] == ' ') {
                ++r;
            }
            while(r < n && s[r] != ' ') {
                s[l++] = s[r++];
            }
            if(r < n) {
                s[l++] = s[r++];
            }
        }
        int spaces = n - l;
        while(spaces--) {
            s.pop_back();
        }
    }

    void reverseSentence(string& s) {
        int n = s.size();
        for(int i = 0; i < n / 2; ++i) {
            swap(s[i], s[n - 1 - i]);
        }
    }

    void reverseWord(string& s, int l, int r) {
        while(l < r) {
            swap(s[l++], s[r--]);
        }
    }
public:
    string reverseWords(string s) {
        removeWitespace(s);
        cout<<0<<s<<0;
        reverseSentence(s);
        int n = s.size();
        int i = 0;
        while(i < n) {
            int j = i;
            while(j < n && s[j] != ' ') {
                ++j;
            }
            reverseWord(s, i, j - 1);
            i = j + 1;
        }
        return s;
    }
};
