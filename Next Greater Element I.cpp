class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        map<int,int> pos;
        for(int i=0; i<m; ++i) {
            pos[nums1[i]] = i;
        }
        vector<int> ans(m, -1);
        int n = nums2.size();
        vector<int> nge(n, -1);
        stack<int> s;
        for(int i=n-1; i>=0; --i) {
            while(!s.empty() && s.top() <= nums2[i]) {
                s.pop();
            }
            if(!s.empty()) {
                nge[i] = s.top();
            }
            s.push(nums2[i]);
            if(pos.count(nums2[i])) {
                ans[pos[nums2[i]]] = nge[i];
            }
        }
        return ans;
    }
};
