class Solution {
    bool pos(string from, string to) {
        int n=from.size(), m=to.size(), i=0, j=0;
        while(i<n && j<m) {
            if(from[i]==to[j]) ++j;
            ++i;
        }
        return j==m;
    }
    
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans;
        int len=0;
        for(string word: dictionary) {
            if(pos(s, word)) {
                int n=word.size();
                if(n>len) {
                    ans=word;
                    len=n;
                }
                else if(n==len && word<ans) {
                    ans=word;
                }
            }
        }
        return ans;
    }
};
