class RLEIterator {
    queue<vector<int>> q;
    
public:
    RLEIterator(vector<int>& encoding) {
        int n=encoding.size();
        for(int i=0; i<n; i+=2) {
            if(!encoding[i]) continue;
            q.push({encoding[i], encoding[i+1]});
        } 
    }
    
    int next(int n) {
        int last=-1;
        while(n && !q.empty()) {
            last=q.front()[1];
            int sub=min(n, q.front()[0]);
            n-=sub;
            q.front()[0]-=sub;
            if(!q.front()[0]) q.pop();
        }
        if(n) return -1;
        return last;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */
