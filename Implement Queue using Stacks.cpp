class MyQueue {
    stack<int> in, out;
    
public:
    MyQueue() {
        ;
    }
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        if(empty()) return -1;
        if(out.empty()) {
            while(!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
        int top=out.top();
        out.pop();
        return top;
    }
    
    int peek() {
        if(empty()) return -1;
        if(out.empty()) {
            while(!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
        return out.top();
    }
    
    bool empty() {
        return in.empty() && out.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
