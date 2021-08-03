class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<bool> pres(2005);
        for(int i: arr) {
            pres[i]=true;
        }
        int ans=1, cnt=1;
        while(cnt<=k) {
            if(!pres[ans]) {
                ++ans;
                ++cnt;
            }
            else {
                ++ans;
            }
        }
        return ans-1;
    }
};
