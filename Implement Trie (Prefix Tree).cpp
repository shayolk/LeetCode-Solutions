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
    
    bool search(string word) {
        node* t=root;
        for(char c: word) {
            if(!t->present(c)) {
                return false;
            }
            t=t->get(c);
        }
        return t->getEnd();
    }
    
    bool startsWith(string prefix) {
        node* t=root;
        for(char c: prefix) {
            if(!t->present(c)) {
                return false;
            }
            t=t->get(c);
        }
        return t;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
