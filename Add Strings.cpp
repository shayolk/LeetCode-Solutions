class Solution {
    int n,m;
    
    string add(int i, int j, int c, string& a, string& b) {
        if(i>=n && j>=m && !c) {
            return "";
        }
        int sum=c;
        if(i<n) {
            sum+=(a[i]-'0');
        }
        if(j<m) {
            sum+=(b[j]-'0');
        }
        return to_string(sum%10)+add(i+1, j+1, sum/10, a, b);
    }
    
public:
    string addStrings(string num1, string num2) {
        n=num1.size();
        m=num2.size();
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string ans=add(0, 0, 0, num1, num2);
        reverse(ans.begin(), ans.end());
        if(ans.empty()) {
            ans="0";
        }
        return ans;
    }
};
