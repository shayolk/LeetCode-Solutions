class MinStack {
    long long minm;
    stack<long long> s;
    
public:
    MinStack() {
        minm=1e11;
    }
    
    void push(int val) {
        if(s.empty()) {
            s.push(val);
            minm=val;
        }
        else if(val<minm) {
            s.push(2ll*val-minm);
            minm=val;
        }
        else {
            s.push(val);
        }
    }
    
    void pop() {
        if(s.empty()) return;
        if(s.top()<minm) {
            minm=2ll*minm-s.top();
        }
        s.pop();
    }
    
    int top() {
        if(s.empty()) return -1;
        if(s.top()<minm) {
            return minm;
        }
        return s.top();
    }
    
    int getMin() {
        return minm;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
