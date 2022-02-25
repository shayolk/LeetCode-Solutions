class LRUCache {
    struct node {
        int key, val;
        node *prev, *next;
        node(int k=-1, int v=-1) {
            key=k;
            val=v;
            prev=next=NULL;
        }
    };
    
    void insert(node* t) {
        t->prev=beg;
        t->next=beg->next;
        beg->next->prev=t;
        beg->next=t;
    }
    
    void del(node* t) {
        t->prev->next=t->next;
        t->next->prev=t->prev;
    }
    
    int cap;
    node *beg, *end;
    map<int,node*> mp;
    
public:
    LRUCache(int capacity) {
        cap=capacity;
        mp.clear();
        beg=new node();
        end=new node();
        beg->next=end;
        end->prev=beg;
    }
    
    int get(int key) {
        if(!mp.count(key)) return -1;
        node* t=mp[key];
        del(t);
        insert(t);
        return t->val;
    }
    
    void put(int key, int value) {
        if(mp.count(key)) {
            node* t=mp[key];
            t->val=value;
            del(t);
            insert(t);
            return;
        }
        if(mp.size()>=cap) {
            mp.erase(end->prev->key);
            del(end->prev);
        }
        node* t=new node(key, value);
        mp[key]=t;
        insert(t);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
