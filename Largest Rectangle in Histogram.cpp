class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size(), ans=0, ls, rs, h;
        stack<int> s;
        for(int i=0; i<=n; ++i) {
            while(!s.empty() && (i==n || heights[i]<=heights[s.top()])) {
                h=heights[s.top()];
                s.pop();
                ls=s.empty()?-1:s.top();
                rs=i;
                ans=max(ans, h*(rs-ls-1));
            }
            s.push(i);
        }
        return ans;
    }
};
