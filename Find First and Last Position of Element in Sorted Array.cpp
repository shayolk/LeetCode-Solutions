class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        bool found = false;
        vector<int> ans;
        int n = nums.size();
        int lo = 0, hi = n-1, mid;
        while(lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if(nums[mid] == target) {
                found = true;
                break;
            }
            else if(nums[mid] < target) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        if(not found) {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        int lo1 = 0, hi1 = mid - 1, mid1, ans1 = mid;
        while(lo1 <= hi1) {
            mid1 = lo1 + (hi1 - lo1) / 2;
            cout<<mid1<<" ";
            if(nums[mid1] == target) {
                ans1 = mid1;
                hi1 = mid1 - 1;
            }
            else {
                lo1 = mid1 + 1;
            }
        }
        ans.push_back(ans1);
        cout<<endl;
        int lo2 = mid + 1, hi2 = n - 1, mid2, ans2 = mid;
        while(lo2 <= hi2) {
            mid2 = lo2 + (hi2 - lo2) / 2;
            cout<<mid2<<" ";
            if(nums[mid2] == target) {
                ans2 = mid2;
                lo2 = mid2 + 1;
            }
            else {
                hi2 = mid2 - 1;
            }
        }
        ans.push_back(ans2);
        return ans;
    }
};
