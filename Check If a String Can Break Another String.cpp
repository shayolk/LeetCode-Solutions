class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        bool x=true, y=true;
        for(int i=0; i<s1.size(); ++i) {
            x &= s1[i]>=s2[i];
            y &= s2[i]>=s1[i];
        }
        return x or y;
    }
};
