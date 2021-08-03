// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lo = 1, hi = n, mid;
        mid = lo + (hi - lo) / 2;
        while(lo<=hi) {
            if(isBadVersion(mid))
                hi = mid - 1;
            else
                lo = mid + 1;
            mid = lo + (hi - lo) / 2;
        }
        return mid;
    }
};
