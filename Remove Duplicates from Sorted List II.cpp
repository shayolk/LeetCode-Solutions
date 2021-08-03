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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }
        ListNode* t=head;
        int v=head->val;
        while(t && t->val==v) {
            t=t->next;
        }
        if(t==head->next) {
            head->next=deleteDuplicates(head->next);
            return head;
        }
        return deleteDuplicates(t);
    }
};
