class Solution {
    vector<vector<int>> ans;
    
    void find(int beg, int sum, int b, vector<int> now, vector<int> &a) {
        if(sum>b) return;
        if(sum==b) {
            ans.push_back(now);
            return;
        }
        for(int i=beg; i<a.size(); ++i) {
            now.push_back(a[i]);
            find(i, sum+a[i], b, now, a);
            now.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        find(0, 0, target, vector<int>{}, candidates);
        return ans;
    }
};
