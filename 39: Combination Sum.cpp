class Solution {
    int n;
    vector<vector<int>> combinations;

    void find(int sum, int ind, vector<int>& now, vector<int>& candidates, int& target) {
        if(sum == target) {
            combinations.push_back(now);
            return;
        }
        if(ind == n || sum > target) {
            return;
        }
        find(sum, ind+1, now, candidates, target);
        now.push_back(candidates[ind]);
        find(sum+candidates[ind], ind, now, candidates, target);
        now.pop_back();
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<int> now;
        find(0, 0, now, candidates, target);
        return combinations;
    }
};
