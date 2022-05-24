class Trie {
    struct node {
        vector<node*> links;
        bool flag;
        
        node() {
            links.resize(2, NULL);
            flag=false;
        }
        
        bool present(char c) {
            return links[c-'0'];
        }
        
        node* get(char c) {
            return links[c-'0'];
        }
        
        void set(char c, node* link) {
            links[c-'0']=link;
        }
        
        bool getEnd() {
            return flag;
        }
        
        void setEnd() {
            flag=true;
        }
    };
    
    node* root;
    
public:
    Trie() {
        root=new node();
    }
    
    void insert(string word) {
        node* t=root;
        for(char c: word) {
            if(!t->present(c)) {
                t->set(c, new node());
            }
            t=t->get(c);
        }
        t->setEnd();
    }
    
    string search(string word) {
        string ans;
        node* t=root;
        for(char c: word) {
            char d=((c=='1')?'0':'1');
            if(t->present(d)) {
                t=t->get(d);
                ans+=d;
            }
            else {
                t=t->get(c);
                ans+=c;
            }
        }
        return ans;
    }
};

class Solution {
    const int BITS=31;
    Trie trie;
    
    string convert(int n) {
        string ret(BITS, '0');
        for(int bit=0; bit<BITS; ++bit) {
            if(n & (1<<bit)) {
                ret[bit]='1';
            }
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
    
    int convert(string s) {
        int ans=0;
        reverse(s.begin(), s.end());
        for(int bit=0; bit<BITS; ++bit) {
            if(s[bit]=='1') {
                ans |= (1<<bit);
            }
        }
        return ans;
    }
    
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[1]<b[1];
    }
    
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        int n=queries.size();
        for(int i=0; i<n; ++i) {
            queries[i].push_back(i);
        }
        sort(queries.begin(), queries.end(), cmp);
        vector<int> ans(n, -1);
        auto itr=nums.begin();
        for(auto query: queries) {
            if(query[1]<nums[0]) continue;
            while(itr!=nums.end() && *itr<=query[1]) {
                trie.insert(convert(*itr));
                ++itr;
            }
            string s=trie.search(convert(query[0]));
            int now=convert(s)^query[0];
            ans[query[2]]=now;
        }
        return ans;
    }
};
