class Solution {
public:
    string getPermutation(int n, int k) {
        int fact=1, div=n;
        for(int i=2; i<=n; ++i) fact*=i;
        vector<int> num(n);
        iota(num.begin(), num.end(), 1);
        --k;
        string ans;
        for(int i=0; i<n; ++i) {
            fact/=div--;
            int pos=k/fact;
            k%=fact;
            ans+=to_string(num[pos]);
            num.erase(num.begin()+pos);
        }
        return ans;
    }
};
