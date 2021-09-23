class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n=arr.size(), ans=0;
        for(int bit=0; bit<(1<<n); ++bit) {
            int now=0;
            bool flag=true;
            vector<bool> vis(26);
            for(int i=0; i<n; ++i) {
                if(bit & (1<<i)) {
                    for(char c: arr[i]) {
                        if(vis[c-'a']) {
                            flag=false;
                            break;
                        }
                        vis[c-'a']=true;
                    }
                    now+=arr[i].size();
                }
            }
            if(flag) ans=max(ans, now);
        }
        return ans;
    }
};
