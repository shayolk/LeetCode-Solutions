class LRUCache {
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k = -2, int v = -1) {
            key = k;
            value = v;
            prev = NULL;
            next = NULL;
        }

        int getKey() {
            return key;
        }

        int getValue() {
            return value;
        }

        void setValue(int v) {
            value = v;
        }

        Node* getPrev() {
            return prev;
        }

        void setPrev(Node* p) {
            prev = p;
        }

        Node* getNext() {
            return next;
        }

        void setNext(Node* n) {
            next = n;
        }
    };

    int capacity;
    Node* head;
    Node* tail;
    map<int,Node*> pos;

    void insert(Node* node) {
        node->setPrev(head);
        node->setNext(head->getNext());
        head->getNext()->setPrev(node);
        head->setNext(node);
    }

    void remove(Node* node) {
        Node* prev = node->getPrev();
        Node* next = node->getNext();
        if(prev) {
            prev->setNext(next);
        }
        if(next) {
            next->setPrev(prev);
        }
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node();
        tail = new Node();
        head->setNext(tail);
        tail->setPrev(head);
    }
    
    int get(int key) {
        if(!pos.count(key)) {
            return -1;
        }
        Node* node = pos[key];
        remove(node);
        insert(node);
        return node->getValue();
    }
    
    void put(int key, int value) {
        if(pos.count(key)) {
            Node* node = pos[key];
            node->setValue(value);
            remove(node);
            insert(node);
            return;
        }
        if(capacity == 0) {
            Node* tmp = tail->prev;
            pos.erase(tmp->getKey());
            remove(tmp);
            delete(tmp);
            ++capacity;
        }
        Node* node = new Node(key, value);
        pos[key] = node;
        insert(node);
        --capacity;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
