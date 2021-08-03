class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue <int> p;
        for(int i: stones)  p.push(i);
        while(p.size()>2) {
            int a=p.top();
            p.pop();
            int b=p.top();
            p.pop();
            if(a==b)    continue;
            p.push(max(a,b)-min(a,b));
        }
        if(p.size()==1)     return p.top();
        int a=p.top();
        p.pop();
        int b=p.top();
        p.pop();
        if(a==b)    return 0;
        return max(a,b)-min(a,b);
    }
};
