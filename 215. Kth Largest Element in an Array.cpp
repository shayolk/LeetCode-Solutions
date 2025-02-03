class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i = 0; i < k; ++i) {
            pq.push(nums[i]);
        }
        int res = pq.top();
        for(int i = k; i < n; ++i) {
            pq.push(nums[i]);
            pq.pop();
            res = max(res, pq.top());
        }
        return res;
    }
};

/*
class Solution {
    int partition(vector<int>& nums, int l, int r) {
        int pos = l + rand() % (r - l + 1);
        swap(nums[pos], nums[r]);
        int i = l;
        for(int j = l; j < r; ++j) {
            if(nums[j] <= nums[r]) {
                swap(nums[j], nums[i++]);
            }
        }
        swap(nums[i], nums[r]);
        return i;
    }

    int find(vector<int>& nums, int k, int l, int r) {
        if(l > r) {
            return -1;
        }
        int pos = partition(nums, l, r);
        if(k < pos) {
            return find(nums, k, l, pos - 1);
        }
        if(k > pos) {
            return find(nums, k, pos + 1, r);
        }
        return nums[pos];
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return find(nums, n - k, 0, n - 1);
    }
};
*/
