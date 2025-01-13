class Solution {
    int n;
    vector<vector<int>> combinations;

    void find(int ind, int target, vector<int>& now, vector<int>& candidates) {
        if(target == 0) {
            combinations.push_back(now);
            return;
        }
        if(ind == n || target < 0) {
            return;
        }
        for(int i=ind; i<n; ++i) {
            if(candidates[i] > target) {
                break;
            }
            if(i != ind && candidates[i] == candidates[i-1]) {
                continue;
            }
            now.push_back(candidates[i]);
            find(i+1, target-candidates[i], now, candidates);
            now.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<int> now;
        find(0, target, now, candidates);
        return combinations;
    }
};
