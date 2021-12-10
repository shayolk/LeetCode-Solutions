class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret{{1}};
        for(int i=1; i<numRows; ++i) {
            vector<int> now{1};
            int n=ret.back().size();
            for(int j=1; j<n; ++j) {
                now.push_back(ret.back()[j-1]+ret.back()[j]);
            }
            now.push_back(1);
            ret.push_back(now);
        }
        return ret;
    }
};
