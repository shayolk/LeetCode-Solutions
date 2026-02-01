class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        int st = intervals[0][0];
        int ed = intervals[0][1];
        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] <= ed) {
                ed = max(ed, intervals[i][1]);
            } else {
                merged.push_back({st, ed});
                st = intervals[i][0];
                ed = intervals[i][1];
            }
        }
        merged.push_back({st, ed});
        return merged;
    }
};
