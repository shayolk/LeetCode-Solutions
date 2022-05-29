class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size(), ans=0;
        vector<int> hash(n);
        for(int i=0; i<n; ++i) {
            for(char c: words[i]) {
                hash[i] |= (1<<(c-'a'));
            }
            for(int j=0; j<i; ++j) {
                if(!(hash[i] & hash[j])) {
                    ans=max(ans, int(words[i].size()*words[j].size()));
                }
            }
        }
        return ans;
    }
};
