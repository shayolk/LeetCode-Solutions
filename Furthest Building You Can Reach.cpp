class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n=heights.size();
        priority_queue<int> steps;
        int i;
        for(i=1; i<n; ++i) {
            if(heights[i]>heights[i-1]) {
                bricks-=(heights[i]-heights[i-1]);
                steps.push(heights[i]-heights[i-1]);
                if(bricks<0) {
                    bricks+=steps.top();
                    steps.pop();
                    --ladders;
                }
                if(ladders<0) return i-1;
            }
        }
        return i-1;
    }
};
