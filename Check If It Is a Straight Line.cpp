class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        vector<int> p1 = coordinates[0], p2 = coordinates[1];
        float m = 1.0*(p2[1]-p1[1])/(p2[0]-p1[0]);
        float c = p1[1] - m*p1[0];
        cout<<m<<" "<<c<<endl;
        int n = coordinates.size();
        for(int i = 1; i < n - 1; ++i) {
            p1 = coordinates[i];
            p2 = coordinates[i+1];
            float m1 = 1.0*(p2[1]-p1[1])/(p2[0]-p1[0]);
            float c1 = p1[1] - m1*p1[0];
            cout<<m1<<" "<<c1<<endl;
            if(m1 != m or c1 != c) {
                return false;
            }
        }
        return true;
    }
};
