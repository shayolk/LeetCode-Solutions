class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        char a[3][3];
        int turn=1, n=moves.size();
        for(auto m: moves) {
            a[m[0]][m[1]]=turn?'X':'O';
            turn^=1;
        }
        for(int i=0; i<3; ++i) {
            if(a[i][0]==a[i][1] && a[i][1]==a[i][2]) {
                return a[i][0]=='X'?"A":"B";
            }
            if(a[0][i]==a[1][i] && a[1][i]==a[2][i]) {
                return a[0][i]=='X'?"A":"B";
            }
        }
        if(a[0][0]==a[1][1] && a[1][1]==a[2][2]) {
            return a[1][1]=='X'?"A":"B";
        }
        if(a[0][2]==a[1][1] && a[1][1]==a[2][0]) {
            return a[1][1]=='X'?"A":"B";
        }
        return n==9?"Draw":"Pending";
    }
};
