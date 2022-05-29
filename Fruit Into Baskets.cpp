class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size(), a=-1, b=-1, last=-1, ans=0;
        deque<int> da, db;
        for(int i=0; i<n; ++i) {
            if(fruits[i]==a) {
                da.push_back(i);
            }
            else if(fruits[i]==b) {
                db.push_back(i);
            }
            else {
                if(last==a) {
                    if(!db.empty()) {
                        while(!da.empty() && da.front()<db.back()) {
                            da.pop_front();
                        }
                    }
                    db.clear();
                    db.push_back(i);
                    b=fruits[i];
                }
                else {
                    if(!da.empty()) {
                        while(!db.empty() && db.front()<da.back()) {
                            db.pop_front();
                        }
                    }
                    da.clear();
                    da.push_back(i);
                    a=fruits[i];
                }
            }
            last=fruits[i];
            ans=max(ans, (int)da.size()+(int)db.size());
        }
        return ans;
    }
};
