class NumArray {
    vector<int> pref {0};
    
public:
    NumArray(vector<int>& nums) {
        for(int x: nums) {
            pref.push_back(pref.back()+x);
        }
    }
    
    int sumRange(int left, int right) {
        return pref[right+1]-pref[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
