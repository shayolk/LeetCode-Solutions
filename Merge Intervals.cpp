class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int first=intervals[0][0], last=intervals[0][1], n=intervals.size();
        for(int i=1; i<n; ++i) {
            if(intervals[i][0]<=last) {
                last=max(last, intervals[i][1]);
            }
            else {
                ans.push_back({first, last});
                first=intervals[i][0];
                last=intervals[i][1];
            }
        }
        ans.push_back({first, last});
        return ans;
    }
};
