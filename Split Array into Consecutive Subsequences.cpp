class Solution {
    bool valid(int l, int r, vector<int>& nums) {
        int cnt=0, one=0, two=0, tot=0;
        for(int i=l; i<=r; ++i) {
            if(i>l && nums[i]==nums[i-1]) {
                ++cnt;
            }
            else if(cnt<one+two) {
                return false;
            }
            else {
                two=one;
                one=max(0, cnt-tot);
                tot=cnt;
                cnt=1;
            }
        }
        two=one;
        one=max(0, cnt-tot);
        return !one && !two;
    }
    
public:
    bool isPossible(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        for(int i=1; i<n; ++i) {
            if(nums[i]-nums[i-1]>1) {
                if(!valid(left, i-1, nums)) {
                    return false;
                }
                left=i;
            }
        }
        return valid(left, n-1, nums);
    }
};
