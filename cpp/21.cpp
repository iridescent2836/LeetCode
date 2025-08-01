#include "header.h"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;
        
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;

        while(list1 != nullptr && list2 != nullptr){
            if(list1->val > list2->val){
                curr->next = list2;
                list2 = list2->next;
                
            } else {
                curr->next = list1;
                list1 = list1->next;
            }
            curr->next->next = nullptr;
            curr = curr->next;
        }
        if(list1 != nullptr){
            curr->next = list1;
        }
        if(list2 != nullptr){
            curr->next = list2;
        }

        curr = dummy->next;
        delete dummy;
        return curr;
    }
};