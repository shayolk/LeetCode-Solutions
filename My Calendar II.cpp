class MyCalendarTwo {
    const int INF=1e9+5;
    set<pair<int,int>> one, two;
    
public:
    MyCalendarTwo() {
        one.clear();
        two.clear();
    }
    
    bool book(int start, int end) {
        auto ind=two.upper_bound({-INF, start});
        for(auto i=ind; i!=two.end(); ++i) {
            if(i->first>end) break;
            if(start<i->second && i->first<end) {
                return false;
            }
        }
        ind=one.upper_bound({-INF, start});
        for(auto i=ind; i!=one.end(); ++i) {
            if(i->first>end) break;
            if(start<i->second && i->first<end) {
                two.insert({max(start, i->first), min(end, i->second)});
            }
        }
        one.insert({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
