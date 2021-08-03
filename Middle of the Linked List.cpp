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
    ListNode* middleNode(ListNode* head) {
        ListNode* s=head;
        ListNode* d=head;
        while(d!=NULL)
        {
            if(d->next==NULL)   break;
            s=s->next;
            d=d->next->next;
        }
        return s;
    }
};
