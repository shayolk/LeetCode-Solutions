class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        char ans=keysPressed[0];
        int mx=releaseTimes[0], last=releaseTimes[0];
        int n=releaseTimes.size();
        for(int i=1; i<n; ++i) {
            int here=releaseTimes[i]-releaseTimes[i-1];
            if(here>mx) {
                mx=here;
                ans=keysPressed[i];
            }
            else if(here==mx) {
                ans=max(ans, keysPressed[i]);
            }
        }
        return ans;
    }
};
