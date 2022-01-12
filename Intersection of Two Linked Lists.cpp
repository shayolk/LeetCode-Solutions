/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a=headA, *b=headB;
        while(a && b) {
            a=a->next;
            b=b->next;
        }
        ListNode *aa=headA, *bb=headB;
        while(a) {
            a=a->next;
            aa=aa->next;
        }
        while(b) {
            b=b->next;
            bb=bb->next;
        }
        while(aa!=bb) {
            aa=aa->next;
            bb=bb->next;
        }
        return bb;
    }
};
