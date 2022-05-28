class Solution {
    const int INF=1e9+5;
    
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        map<int,int> last;
        vector<int> pref(n);
        last[0]=-1;
        int sum=0;
        for(int i=0; i<n; ++i) {
            sum+=arr[i];
            if(last.count(sum-target)) {
                int j=last[sum-target];
                if(i) pref[i]=min(pref[i-1], i-j);
                else pref[i]=i-j;
            }
            else {
                if(i) pref[i]=pref[i-1];
                else pref[i]=INF;
            }
            last[sum]=i;
        }
        last.clear();
        last[0]=n;
        sum=0;
        int ans=INF, suff=0;
        for(int i=n-1; i>=0; --i) {
            sum+=arr[i];
            if(last.count(sum-target)) {
                int j=last[sum-target];
                if(i+1<n) suff=min(suff, j-i);
                else suff=j-i;
                if(i) ans=min(ans, pref[i-1]+suff);
            }
            else {
                if(i+1<n) suff=suff;
                else suff=INF;
            }
            last[sum]=i;
        }
        if(ans==INF) ans=-1;
        return ans;
    }
};
