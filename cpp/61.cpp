#include "header.h"
/**
 * rotate k steps equals to put the last k nodes to the head of the list. 
 * time: O(N)
 * space: O(1)
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr) return head;
        
        int size = 0;
        ListNode* curr = head;
        while(curr!=nullptr){
            curr = curr->next;
            size++;
        }
        k = k % size;
        if(k == 0) return head;

        ListNode* ahead = head;
        ListNode* behind = head;
        for(int i = 0; i < k; i++){
            ahead = ahead->next;
        }
        while(ahead->next!=nullptr){
            ahead = ahead->next;
            behind = behind->next;
        }

        ListNode* ret = behind->next;
        ahead->next = head;
        behind->next = nullptr;
        return ret;
    }
};