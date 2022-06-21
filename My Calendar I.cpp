class MyCalendar {
    const int INF=1e9+5;
    set<pair<int,int>> event;
    
public:
    MyCalendar() {
        event.clear();
    }
    
    bool book(int start, int end) {
        auto ind=event.lower_bound({-INF, start});
        for(auto i=ind; i!=event.end(); ++i) {
            if(i->first>end) break;
            if(start<i->second && i->first<end) {
                return false;
            }
        }
        event.insert({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
