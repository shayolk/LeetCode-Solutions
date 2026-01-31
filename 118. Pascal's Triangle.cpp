class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> now;
        for(int i=0; i<numRows; ++i) {
            now = { 1 };
            for(int j=1; j<i; ++j) {
                now.push_back(ans.back()[j - 1] + ans.back()[j]);
            }
            if(i) now.push_back(1);
            ans.push_back(now);
        }
        return ans;
    }
};
