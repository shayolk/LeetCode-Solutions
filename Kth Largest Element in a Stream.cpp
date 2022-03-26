class KthLargest {
    int k;
    priority_queue<int,vector<int>,greater<int>> p;
    
public:
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(int n: nums) {
            p.push(n);
        }
        while(p.size()>k) {
            p.pop();
        }
    }
    
    int add(int val) {
        p.push(val);
        if(p.size()>k) {
            p.pop();
        }
        return p.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
