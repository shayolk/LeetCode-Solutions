class Solution {
    int partition(vector<int>& a, int lo, int hi) {
        int pos=lo+rand()%(hi-lo+1);
        swap(a[pos], a[hi]);
        int i=lo;
        for(int j=lo; j<hi; ++j) {
            if(a[j]<=a[hi]) {
                swap(a[i++], a[j]);
            }
        }
        swap(a[i], a[hi]);
        return i;
    }
    
    int kthSmallest(vector<int>& arr, int l, int r, int k) {
        if(l>r) return -1;
        int pos=partition(arr, l, r);
        if(pos==k-1) return arr[pos];
        if(pos>k-1) return kthSmallest(arr, l, pos-1, k);
        return kthSmallest(arr, pos+1, r, k);
    }
    
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        return kthSmallest(nums, 0, n-1, n-k+1);
    }
};
