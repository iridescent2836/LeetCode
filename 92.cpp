#include "header.h"

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || head->next == nullptr || left == right) return head;
        ListNode* dummy = new ListNode(0, head);
        ListNode* pre = dummy;
        // pre is the node that before the beginning of the node
        for(int i = 1; i < left; i++){
            pre = pre->next;
        }

        ListNode* curr = pre->next;
        ListNode* next = curr->next;
        for(int i = 0; i<right - left; i++){
            curr->next = next->next;
            next->next = pre->next;
            pre->next = next;
            next = curr->next;
        }

        ListNode* ret = dummy->next;
        delete dummy;

        return ret;
    }
        
};
