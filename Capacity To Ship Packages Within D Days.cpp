class Solution {
    bool check(vector<int>& weights, int days, int per) {
        int need=1, each=weights[0], n=weights.size();
        for(int i=1; i<n; ++i) {
            if(each+weights[i]<=per) {
                each+=weights[i];
            }
            else {
                ++need;
                each=weights[i];
            }
        }
        return need<=days;
    }
    
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int lo=0, hi=0;
        for(int w: weights) {
            lo=max(lo, w);
            hi+=w;
        }
        int ans=hi;
        while(lo<=hi) {
            int mid=lo+(hi-lo)/2;
            if(check(weights, days, mid)) {
                ans=mid;
                hi=mid-1;
            }
            else {
                lo=mid+1;
            }
        }
        return ans;
    }
};
