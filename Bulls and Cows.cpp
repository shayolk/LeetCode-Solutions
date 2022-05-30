class Solution {
public:
    string getHint(string secret, string guess) {
        int n=secret.size();
        map<char,int> m;
        int x=0, y=0;
        for(int i=0; i<n; ++i) {
            if(secret[i]==guess[i]) {
                ++x;
            }
            else {
                ++m[secret[i]];
            }
        }        
        for(int i=0; i<n; ++i) {
            if(secret[i]==guess[i]) continue;
            if(m[guess[i]]) {
                ++y;
                --m[guess[i]];
            }
        }
        return to_string(x)+"A"+to_string(y)+"B";
    }
};
