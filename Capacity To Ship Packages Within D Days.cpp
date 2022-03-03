class Solution {
    bool check(vector<int>& weights, int days, int per) {
        int need=1, each=0;
        for(int w: weights) {
            each+=w;
            if(each>per) {
                ++need;
                each=w;
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
