class Solution {
    int count(int now, int n, vector<bool> &vis) {
        if(now==n+1) return 1;
        int here=0;
        for(int i=1; i<=n; ++i) {
            if(!vis[i] && (i%now==0 || now%i==0)) {
                vis[i]=true;
                here+=count(now+1,n,vis);
                vis[i]=false;
            }
        }
        return here;
    }
public:
    int countArrangement(int n) {
        vector<bool> vis(n+1);
        return count(1,n,vis);
    }
};
