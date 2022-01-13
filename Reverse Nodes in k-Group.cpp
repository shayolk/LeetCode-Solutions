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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return head;
        ListNode *prev=NULL, *curr=head, *next=NULL, *temp=head;
        int cnt=0;
        while(cnt<k && temp) {
            temp=temp->next;
            ++cnt;
        }
        if(cnt==k) {
            while(cnt-- && curr) {
                next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
            head->next=reverseKGroup(curr, k);
            return prev;
        }
        return head;
    }
};
