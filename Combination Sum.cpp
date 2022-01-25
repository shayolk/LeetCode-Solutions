class Solution {
    vector<vector<int>> ans;
    
    void find(int i, int n, int target, vector<int>& now, vector<int>& a) {
        if(target==0) {
            ans.push_back(now);
            return;
        }
        if(i==n || target<0) {
            return;
        }
        find(i+1, n, target, now, a);
        now.push_back(a[i]);
        find(i, n, target-a[i], now, a);
        now.pop_back();
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> now;
        find(0, (int)candidates.size(), target, now, candidates);
        return ans;
    }
};
