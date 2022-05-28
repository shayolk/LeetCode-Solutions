class Solution {
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if(a[1]==b[1]) return 0ll+a[1]-a[0]+a[2]<0ll+b[1]-b[0]+b[2];
        return a[1]<b[1];
    }
        
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        int m=rides.size();
        sort(rides.begin(), rides.end(), cmp);
        vector<int> end;
        for(auto ride: rides) {
            end.push_back(ride[1]);
        }
        vector<long long> dp(m+1);
        for(int i=1; i<=m; ++i) {
            dp[i]=0ll+rides[i-1][1]-rides[i-1][0]+rides[i-1][2];
            int j=upper_bound(end.begin(), end.begin()+i, rides[i-1][0])-end.begin();
            if(j<i) {
                dp[i]+=dp[j];
            }
            dp[i]=max(dp[i], dp[i-1]);
        }
        return dp[m];
    }
};
