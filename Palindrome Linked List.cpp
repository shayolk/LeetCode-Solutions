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
    ListNode* start;
    
    bool check(ListNode* head) {
        if(!head || !start) return true;
        bool ahead=check(head->next);
        bool now=head->val==start->val;
        start=start->next;
        return ahead && now;
    }
public:
    bool isPalindrome(ListNode* head) {
        start=head;
        return check(head);
    }
};
