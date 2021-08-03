class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int ans = 0;
        for(char x: S)
            ans += (find(J.begin(), J.end(), x) != J.end());
        return ans;
    }
};
