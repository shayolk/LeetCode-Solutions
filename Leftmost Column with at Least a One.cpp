/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> v=binaryMatrix.dimensions();
        int n=v[0], m=v[1];
        int mn=m, x=1;
        int st=0, ed=m-1, mid;
        while(st<=ed) {
            mid=st+(ed-st)/2;
            if(binaryMatrix.get(0,mid)) {
                mn=mid;
                ed=mid-1;
            }
            else
                st=mid+1;
            if(mn==0)
                return 0;
        }
        while(x<n) {
            st=0, ed=m-1;
            while(st<=ed) {
                mid=st+(ed-st)/2;
                if(binaryMatrix.get(x,mid)) {
                    mn=min(mn,mid);
                    ed=mid-1;
                }
                else
                    st=mid+1;
            }
            ++x;
            if(mn==0)
                return 0;
        }
        if(mn==m)
            mn=-1;
        return mn;
    }
};
