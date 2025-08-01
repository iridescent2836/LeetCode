#include "header.h"

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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// ignore the memory of the removed ListNode
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* curr = dummy;
        int dup = 0;
        while(curr->next && curr->next->next){
            if(curr->next->val == curr->next->next->val){
                int dup = curr->next->val;
                while(curr->next && curr->next->val == dup){
                    curr->next = curr->next->next;
                }
            } else {
                curr = curr->next;
            }
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};