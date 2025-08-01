#include "header.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;

        int s = 0, c = 0;
        // sum the 2 lists.
        while(curr1 != nullptr && curr2 != nullptr){
            s = (curr1->val + curr2->val + c) % 10;
            c = (curr1->val + curr2->val + c) / 10;
            curr->next = new ListNode(s);
            curr1 = curr1->next;
            curr2 = curr2->next;
            curr = curr->next;
        }
        
        // sum the rest if it exists.
        while(curr1 != nullptr){
            s = (curr1->val + c) % 10;
            c = (curr1->val + c) / 10;
            curr->next = new ListNode(s);
            curr1 = curr1->next;
            curr = curr->next;
        }

        // sum the rest if it exists.
        while(curr2 != nullptr){
            s = (curr2->val + c) % 10;
            c = (curr2->val + c) / 10;
            curr->next = new ListNode(s);
            curr2 = curr2->next;
            curr = curr->next;
        }
        
        // clear the final carry if it exists. 
        if(c!=0){
            curr->next = new ListNode(c);
        }

        ListNode* ret = dummy->next;
        delete dummy;
        return ret;
    }
};