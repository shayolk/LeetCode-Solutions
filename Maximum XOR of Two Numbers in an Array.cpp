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
    
public:
    int findMaximumXOR(vector<int>& nums) {
        vector<string> strs;
        for(int num: nums) {
            strs.push_back(convert(num));
        }
        for(string str: strs) {
            trie.insert(str);
        }
        int ans=0;
        for(string str: strs) {
            string s=trie.search(str);
            int now=convert(s)^convert(str);
            ans=max(ans, now);
        }
        return ans;
    }
};
