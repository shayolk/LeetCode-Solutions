class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int ans=0, n=heaters.size();
        for(int house: houses) {
            int ind=lower_bound(heaters.begin(), heaters.end(), house)-heaters.begin();
            int here=1e9+5;
            if(ind<n) here=min(here, abs(heaters[ind]-house));
            if(ind-1>=0) here=min(here, abs(heaters[ind-1]-house));
            ans=max(ans, here);
        }
        return ans;
    }
};
