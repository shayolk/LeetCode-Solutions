class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> cnt(26);
        for(char c: s) {
            ++cnt[c-'a'];
        }
        vector<bool> vis(26);
        string ans;
        for(char c: s) {
            --cnt[c-'a'];
            if(!vis[c-'a']) {
                while(!ans.empty() && ans.back()>c && cnt[ans.back()-'a']) {
                    vis[ans.back()-'a']=false;
                    ans.pop_back();
                }
                ans+=c;
                vis[c-'a']=true;
            }
        }
        return ans;
    }
};
