class Solution {
    int merge(vector<int>& a, int l, int r) {
        if(l>=r) return 0;
        int mid=l+(r-l)/2;
        int ans = merge(a,l,mid) + merge(a,mid+1,r);
        int i, j=mid+1;
        for(i=l; i<=mid; ++i) {
            while(j<=r && 1LL*a[i]>2LL*a[j]) {
                ++j;
            }
            ans+=j-(mid+1);
        }
        vector<int> x,y;
        x.assign(a.begin()+l, a.begin()+mid+1);
        y.assign(a.begin()+mid+1, a.begin()+r+1);
        i=0, j=0;
        int n=mid-l+1, m=r-mid, k=l;
        while(i<n && j<m) {
            if(x[i]<y[j]) a[k++]=x[i++];
            else a[k++]=y[j++];
        }
        while(i<n) {
            a[k++]=x[i++];
        }while(j<m) {
            a[k++]=y[j++];
        }
        return ans;
    }
    
public:
    int reversePairs(vector<int>& nums) {
        return merge(nums, 0, (int)nums.size()-1);
    }
};
