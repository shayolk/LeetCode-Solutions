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
    ListNode* add(ListNode* l1, ListNode* l2, int c) {
        if(!l1 && !l2 && !c) {
            return NULL;
        }
        // if(l1) cout<<l1->val<<" ";
        // if(l2) cout<<l2->val<<"\n";
        int sum=c+(l1?l1->val:0)+(l2?l2->val:0);
        c=sum/10;
        // cout<<c<<" "<<sum<<"\n\n";
        ListNode* t=new ListNode(sum%10);
        t->next=add((l1?l1->next:NULL), (l2?l2->next:NULL), c);
        return t;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return add(l1, l2, 0);
    }
};
