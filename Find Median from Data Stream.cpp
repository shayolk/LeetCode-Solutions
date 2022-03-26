class MedianFinder {
    priority_queue<int> left;
    priority_queue<int,vector<int>,greater<int>> right;
    
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        right.push(num);
        left.push(right.top());
        right.pop();
        if(left.size()-right.size()>1) {
            right.push(left.top());
            left.pop();
        }
    }
    
    double findMedian() {
        if(left.empty()) return 0;
        if(left.size()==right.size()) return (left.top()+right.top())/2.0;
        return left.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
