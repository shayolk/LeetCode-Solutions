class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(), arr.end());
        map<int,int> m;
        for(int x: arr) {
            ++m[x];
        }
        for(int x: arr) {
            if(m[x] && m[2*x]) {
                --m[x];
                --m[2*x];
            }
        }
        for(auto i: m) {
            if(i.second) {
                return false;
            }
        }
        return true;
    }
};
