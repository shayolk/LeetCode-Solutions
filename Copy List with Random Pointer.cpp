/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        Node* t=head;
        while(t) {
            Node* tmp=new Node(t->val), *nxt=t->next;
            t->next=tmp;
            tmp->next=nxt;
            t=nxt;
        }
        t=head;
        Node* start=head->next;
        while(t) {
            if(t->random) {
                t->next->random=t->random->next;
            }
            t=t->next->next;
        }
        t=head;
        while(t) {
            Node* nxt=t->next->next;
            if(nxt) {
                t->next->next=nxt->next;
            }
            t->next=nxt;
            t=nxt;
        }
        return start;
    }
};
