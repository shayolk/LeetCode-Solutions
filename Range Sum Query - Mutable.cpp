class NumArray {
    int n;
    vector<int> tree;
    
    void build(int root, int l, int r, vector<int>& nums) {
        if(l==r) {
            tree[root]=nums[l];
            return;
        }
        int mid=l+(r-l)/2;
        build(2*root, l, mid, nums);
        build(2*root+1, mid+1, r, nums);
        tree[root]=tree[2*root]+tree[2*root+1];
    }
    
    void update(int root, int l, int r, int index, int val) {
        if(l==r) {
            tree[root]=val;
            return;
        }
        int mid=l+(r-l)/2;
        if(index<=mid) update(2*root, l, mid, index, val);
        else update(2*root+1, mid+1, r, index, val);
        tree[root]=tree[2*root]+tree[2*root+1];
    }
    
    int query(int root, int l, int r, int left, int right) {
        if(r<left || right<l) return 0;
        if(left<=l && r<=right) return tree[root];
        int mid=l+(r-l)/2;
        return query(2*root, l, mid, left, right)+query(2*root+1, mid+1, r, left, right);
    }
    
public:
    NumArray(vector<int>& nums) {
        n=nums.size();
        tree.resize(4*n);
        build(1, 0, n-1, nums);
    }
    
    void update(int index, int val) {
        update(1, 0, n-1, index, val);
    }
    
    int sumRange(int left, int right) {
        return query(1, 0, n-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
