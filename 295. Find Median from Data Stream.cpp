class MedianFinder {
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

public:
    MedianFinder() {}
    
    void addNum(int num) {
        left.push(num);
        right.push(left.top());
        left.pop();
        if(right.size() - left.size() > 1) {
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if(right.empty()) {
            return -1;
        }
        if(left.size() != right.size()) {
            return right.top();
        }
        return (left.top() + right.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
