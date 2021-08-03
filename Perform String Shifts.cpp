class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int left=0, right=0;
        for(auto i: shift) {
            if(i[0]) {
                right+=i[1];
            }
            else {
                left+=i[1];
            }
        }
        int n=s.size();
        int move=abs(left-right)%n;
        if(left==right)
            return s;
        if(left>right)
            return s.substr(move,n-move) + s.substr(0,move);
        return s.substr(n-move,move) + s.substr(0,n-move);
    }
};
