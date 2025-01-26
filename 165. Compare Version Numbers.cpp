class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1 = version1.size();
        int n2 = version2.size();
        int i1 = 0, i2 = 0, val1 = 0, val2 = 0;
        while(i1 < n1 && i2 < n2) {
            while(i1 < n1 && version1[i1] != '.') {
                val1 = (10 * val1) + (version1[i1] - '0');
                ++i1;
            }
            while(i2 < n2 && version2[i2] != '.') {
                val2 = (10 * val2) + (version2[i2] - '0');
                ++i2;
            }
            if(val1 < val2) {
                return -1;
            }
            if(val1 > val2) {
                return 1;
            }
            ++i1;
            ++i2;
            val1 = 0;
            val2 = 0;
        }
        while(i1 < n1) {
            if(version1[i1] != '0' && version1[i1] != '.') {
                return 1;
            }
            ++i1;
        }
        while(i2 < n2) {
            if(version2[i2] != '0' && version2[i2] != '.') {
                return -1;
            }
            ++i2;
        }
        return 0;
    }
};
