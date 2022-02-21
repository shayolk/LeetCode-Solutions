class Solution {
    const int INF=1e9+5;
    
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2=nums2.size();
        if(n1>n2) return findMedianSortedArrays(nums2, nums1);
        int left=(n1+n2)/2;
        int lo=max(0, left-n2), hi=min(n1, left), mid;
        while(lo<=hi) {
            mid=lo+(hi-lo)/2;
            int one=mid, two=left-mid;
            int l1=one?nums1[one-1]:-INF, r1=(one<n1)?nums1[one]:INF;
            int l2=two?nums2[two-1]:-INF, r2=(two<n2)?nums2[two]:INF;
            if(max(l1, l2)<=min(r1, r2)) {
                if((n1+n2)%2) return min(r1, r2);
                return (max(l1, l2)+min(r1, r2))/2.0;
            }
            if(l1>r2) hi=mid-1;
            else lo=mid+1;
        }
        return -1;
    }
};
