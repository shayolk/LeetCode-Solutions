class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        vector<int> great(n);
        stack<int> s;
        for(int i=0; i<n; ++i) {
            while(!s.empty() && nums2[s.top()]<nums2[i]) {
                great[s.top()]=nums2[i];
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()) {
            great[s.top()]=-1;
            s.pop();
        }
        map<int,int> mp;
        for(int i=0; i<n; ++i) {
            mp[nums2[i]]=i;
        }
        vector<int> ans;
        for(int i: nums1) {
            ans.push_back(great[mp[i]]);
        }
        return ans;
    }
};
