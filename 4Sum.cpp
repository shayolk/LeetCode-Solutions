class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n=nums.size(), i=0;
        while(i<n) {
            int j=i+1;
            while(j<n) {
                int l=j+1, r=n-1;
                while(l<r) {
                    long long sum=0LL+nums[i]+nums[j]+nums[l]+nums[r];
                    if(sum<target) {
                        int ll=nums[l];
                        while(l<r && nums[l]==ll) {
                            ++l;
                        }
                    }
                    else if(sum>target) {
                        int rr=nums[r];
                        while(l<r && nums[r]==rr) {
                            --r;
                        }
                    }
                    else {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        int ll=nums[l];
                        while(l<r && nums[l]==ll) {
                            ++l;
                        }
                        int rr=nums[r];
                        while(l<r && nums[r]==rr) {
                            --r;
                        }
                    }
                }
                int jj=nums[j];
                while(j<n && nums[j]==jj) {
                    ++j;
                }
            }
            int ii=nums[i];
            while(i<n && nums[i]==ii) {
                ++i;
            }
        }
        return ans;
    }
};
