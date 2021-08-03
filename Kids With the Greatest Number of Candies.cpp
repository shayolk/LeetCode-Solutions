class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
        int mx=INT_MIN;
        for(int x: candies)
            mx=max(mx,x);
        for(int x: candies)
            ans.push_back(x+extraCandies>=mx);
        return ans;
    }
};
