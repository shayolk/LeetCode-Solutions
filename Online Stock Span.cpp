class StockSpanner {
    int ind;
    stack<int> s;
    vector<int> prices;
    
public:
    StockSpanner() {
        ind=0;
    }
    
    int next(int price) {
        prices.push_back(price);
        while(!s.empty() && prices[s.top()]<=price) {
            s.pop();
        }
        int ans=0;
        if(s.empty()) ans=ind+1;
        else ans=ind-s.top();
        s.push(ind++);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
