class Trie {
    struct node {
        vector<node*> links;
        bool flag;
        
        node() {
            links.resize(26, NULL);
            flag=false;
        }
        
        bool present(char c) {
            return links[c-'a'];
        }
        
        node* get(char c) {
            return links[c-'a'];
        }
        
        void set(char c, node* link) {
            links[c-'a']=link;
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
    
    bool startsWith(string prefix) {
        node* t=root;
        for(char c: prefix) {
            if(!t->present(c)) {
                return false;
            }
            t=t->get(c);
        }
        for(char c='a'; c<='z'; ++c) {
            if(t->present(c)) return true;
        }
        return false;
    }
};

class Solution {
    Trie trie;
    
public:
    int minimumLengthEncoding(vector<string>& words) {
        for(string& word: words) {
            reverse(word.begin(), word.end());
            trie.insert(word);
        }
        int ans=0;
        set<string> s;
        for(string word: words) {
            if(s.count(word) || trie.startsWith(word)) continue;
            ans+=word.size()+1;
            s.insert(word);
        }
        return ans;
    }
};
