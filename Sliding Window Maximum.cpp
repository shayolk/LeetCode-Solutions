class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans(n-k+1);
        deque<int> d;
        for(int i=0; i<n; ++i) {
            while(!d.empty() && d.front()<=i-k) {
                d.pop_front();
            }
            while(!d.empty() && nums[i]>nums[d.back()]) {
                d.pop_back();
            }
            d.push_back(i);
            if(i-k+1>=0) {
                ans[i-k+1]=nums[d.front()];
            }
        }
        return ans;
    }
};
