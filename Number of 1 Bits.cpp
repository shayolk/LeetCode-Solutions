class Solution {
public:
    int hammingWeight(uint32_t n) {
        int bits=0;
        for(int bit=0; bit<32; ++bit) {
            if(n & (1<<bit)) {
                ++bits;
            }
        }
        return bits;
    }
};
