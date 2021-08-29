class Solution {
    struct st {
        int s, e, p;
        st(int s, int e, int p) {
            this->s=s;
            this->e=e;
            this->p=p;
        }
    };
    
    static bool comp(const st& a, const st& b) {
        return a.s<b.s;
    }
    
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=profit.size();
        vector<st> a;
        for(int i=0; i<n; ++i) {
            a.push_back(st(startTime[i], endTime[i], profit[i]));
        }
        sort(a.begin(), a.end(), comp);
        for(int i=0; i<n; ++i) {
            startTime[i]=a[i].s;
            endTime[i]=a[i].e;
            profit[i]=a[i].p;
        }
        int dp[n];
        dp[n-1]=profit[n-1];
        for(int i=n-2; i>=0; --i) {
            dp[i]=profit[i];
            int ind=lower_bound(startTime.begin()+i+1, startTime.end(), endTime[i])-startTime.begin();
            if(ind<n) dp[i]+=dp[ind];
            dp[i]=max(dp[i], dp[i+1]);
        }
        return dp[0];
    }
};
