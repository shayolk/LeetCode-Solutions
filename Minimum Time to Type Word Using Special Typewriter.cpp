class Solution {
public:
    int minTimeToType(string word) {
        int n=word.size();
        vector<int> a(n);
        for(int i=0; i<n; ++i) {
            a[i]=word[i]-'a';
        }
        int ans=n, last=0;
        for(int i=0; i<n; ++i) {
            int mx=max(a[i], last);
            int mn=min(a[i], last);
            ans+=min(mx-mn, mn+26-mx);
            last=a[i];
        }
        return ans;
    }
};
