class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int n = A.size();
        vector<int> pref(n + 1);
        for(int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + A[i];
        }
        int sum, st = 0, ed = 1, ans = n + 1;
        deque<int> d;
        for(int i = 0; i <= n; ++i) {
            while(!d.empty() && pref[i] < pref[d.back()]) {
                d.pop_back();
            }
            while(!d.empty() && pref[i] - pref[d.front()] >= K) {
                ans = min(ans, i - d.front());
                d.pop_front();
            }
            d.push_back(i);
        }
        return ans == n + 1 ? -1 : ans;
    }
};
