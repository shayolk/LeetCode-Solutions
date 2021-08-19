class Solution {
    const int M=1e9+7;
public:
    int numDecodings(string s) {
        int n=s.size();
        long long dp[n+1];
        dp[0]=1;
        for(int i=1; i<=n; ++i) {
            dp[i]=0;
            if(s[i-1]=='*') {
                dp[i]=(dp[i]+(9*dp[i-1])%M)%M;
                if(i>1) {
                    if(s[i-2]=='*') {
                        dp[i]=(dp[i]+(15*dp[i-2])%M)%M;
                    }
                    else if(s[i-2]=='1') {
                        dp[i]=(dp[i]+(9*dp[i-2])%M)%M;
                    }
                    else if(s[i-2]=='2') {
                        dp[i]=(dp[i]+(6*dp[i-2])%M)%M;
                    }
                }
                continue;
            }
            if(s[i-1]!='0') {
                dp[i]=(dp[i]+dp[i-1])%M;
                if(i>1 && s[i-2]=='*') {
                    if(s[i-1]<='6') {
                        dp[i]=(dp[i]+(2*dp[i-2])%M)%M;
                    }
                    else {
                        dp[i]=(dp[i]+dp[i-2])%M;
                    }
                }
            }
            else if(i>1 && s[i-2]=='*') {
                dp[i]=(dp[i]+(2*dp[i-2])%M)%M;
            }
            if(i>1 && (s[i-2]=='1' || (s[i-2]=='2' && s[i-1]<='6'))) {
                dp[i]=(dp[i]+dp[i-2])%M;
            }
        }
        return dp[n];
    }
};
