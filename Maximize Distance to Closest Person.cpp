class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int cnt=0, ans=0, n=seats.size();
        int i=0, j=n-1;
        while(i<n && !seats[i]) {
            ++cnt;
            ++i;
        }
        ans=cnt;
        cnt=0;
        while(j>=0 && !seats[j]) {
            ++cnt;
            --j;
        }
        ans=max(ans, cnt);
        cnt=0;
        while(i<=j) {
            if(seats[i++]) {
                cnt=0;
            }
            else {
                ++cnt;
            }
            ans=max(ans, (cnt+1)/2);
        }
        return ans;
    }
};
