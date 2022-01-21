/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || !k) return head;
        int n=0;
        ListNode *t=head, *start=head, *end;
        while(t) {
            if(!t->next) end=t;
            ++n;
            t=t->next;
        }
        end->next=head;
        k=n-k%n;
        t=head;
        while(--k) {
            t=t->next;
        }
        start=t->next;
        t->next=NULL;
        return start;
    }
};
