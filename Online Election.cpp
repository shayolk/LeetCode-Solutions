class TopVotedCandidate {
    int n;
    vector<pair<int,int>> win;
    
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int m=times.size(), mx=0, p=-1;
        map<int,int> votes;
        for(int i=0; i<m; ++i) {
            ++votes[persons[i]];
            if(votes[persons[i]]>=mx) {
                if(p!=persons[i]) {
                    p=persons[i];
                    win.push_back({times[i], persons[i]});
                }
                if(votes[persons[i]]>mx) {
                    mx=votes[persons[i]];
                }
            }
        }
        n=win.size();
    }
    
    int q(int t) {
        int ind=lower_bound(win.begin(), win.end(), make_pair(t, -1))-win.begin();
        if(ind<n && t==win[ind].first) return win[ind].second;
        return win[ind-1].second;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
