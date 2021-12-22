class Solution {
    int dum=1e9+5;
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size(), val1=dum, val2=dum, cnt1=0, cnt2=0;
        for(int num: nums) {
            if(num==val1) {
                ++cnt1;
            }
            else if(num==val2) {
                ++cnt2;
            }
            else if(cnt1==0) {
                val1=num;
                cnt1=1;
            }
            else if(cnt2==0) {
                val2=num;
                cnt2=1;
            }
            else {
                --cnt1;
                --cnt2;
            }
        }
        cnt1=0, cnt2=0;
        for(int num: nums) {
            if(num==val1) {
                ++cnt1;
            }
            if(num==val2) {
                ++cnt2;
            }
        }
        vector<int> ans;
        if(cnt1>n/3) {
            ans.push_back(val1);
        }
        if(cnt2>n/3) {
            ans.push_back(val2);
        }
        return ans;
    }
};
