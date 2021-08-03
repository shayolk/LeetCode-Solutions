class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero=0;
        auto j=nums.begin();
        for(auto i=nums.begin(); i!=nums.end(); ++i) {
            if(*i)
            {
                *j=*i;
                ++j;
            }
        }
        for(auto i=j; i!=nums.end(); ++i)    *i=0;
    }
};
