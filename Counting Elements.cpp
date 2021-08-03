class Solution {
public:
    int countElements(vector<int>& arr) {
        bool dp[1005];
        fill(dp,dp+1005,false);
        int ans=0;
        for(int i: arr)     dp[i]=true;
        for(int i: arr)     if(dp[i+1])  ++ans;
        return ans;
    }
};
