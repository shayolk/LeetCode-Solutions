class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n=arr.size();
        if(n==1) return 1;
        int ans=arr[0]==arr[1]?1:2, so=1;
        for(int i=2; i<n; ++i) {
            if((arr[i]>arr[i-1] && arr[i-1]<arr[i-2]) || (arr[i]<arr[i-1] && arr[i-1]>arr[i-2])) ++so;
            else if(arr[i]==arr[i-1]) so=0;
            else so=1;
            ans=max(ans, so+1);
        }
        return ans;
    }
};
