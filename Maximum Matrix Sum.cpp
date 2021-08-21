class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int neg=0;
        vector<int> a;
        for(auto i: matrix) {
            for(auto j: i) {
                neg+=(j<0);
                a.push_back(abs(j));
            }
        }
        sort(a.begin(), a.end());
        if(neg%2) a[0]*=-1;
        long long ans=0;
        for(int i: a) {
            ans+=i;
        }
        return ans;
    }
};
