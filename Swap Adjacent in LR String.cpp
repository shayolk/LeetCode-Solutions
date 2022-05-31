class Solution {
public:
    bool canTransform(string start, string end) {
        int n=start.size(), ls=0, le=0, rs=0, re=0;
        for(int i=0; i<n; ++i) {
            if(start[i]=='L') {
                if(rs!=re) return false;
                ++ls;
            }
            else if(start[i]=='R') {
                if(ls!=le) return false;
                ++rs;
            }
            if(end[i]=='L') {
                ++le;
            }
            else if(end[i]=='R') {
                ++re;
            }
            if(ls>le || rs<re) return false;
        }
        return ls==le && rs==re;
    }
};
