class Solution {
    int n, sum;
    vector<int> pre;
    
public:
    Solution(vector<int>& w) {
        n=w.size();
        sum=0;
        for(int i: w) {
            sum+=i;
            pre.push_back(sum);
        }
    }
    
    int pickIndex() {
        int num=rand()%sum+1;
        int ind=lower_bound(pre.begin(), pre.end(), num)-pre.begin();
        return ind;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
