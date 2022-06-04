class Solution {
    vector<pair<char,int>> convert(string s) {
        char ch='#';
        int cnt=0;
        vector<pair<char,int>> ret;
        for(char c: s) {
            if(c==ch) {
                ++cnt;
            }
            else {
                if(cnt) ret.push_back({ch, cnt});
                ch=c;
                cnt=1;
            }
        }
        if(cnt) ret.push_back({ch, cnt});
        return ret;
    }
    
public:
    int expressiveWords(string s, vector<string>& words) {
        vector<pair<char,int>> his=convert(s);
        int n=his.size(), ans=0;
        for(string word: words) {
            vector<pair<char,int>> now=convert(word);
            int m=now.size();
            if(n!=m) continue;
            bool here=true;
            for(int i=0; i<n; ++i) {
                if(his[i].first!=now[i].first) {
                    here=false;
                    break;
                }
                if(his[i].second==now[i].second) continue;
                if(his[i].second<now[i].second || his[i].second<3) {
                    here=false;
                    break;
                }
            }
            if(here) ++ans;
        }
        return ans;
    }
};
