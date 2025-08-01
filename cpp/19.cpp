#include "header.h"

/**
 * a simple, clear and efficient method
 * time: O(size)
 * space: O(1)
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        int size = 0;

        ListNode* curr = head;
        while(curr!=nullptr){
            curr = curr->next;
            size++;
        }

        ListNode* pre = dummy;
        for(int i = 0; i < size - n; i++){
            pre = pre->next;
        }
        curr = pre->next;
        pre->next = pre->next->next;
        delete curr;
        ListNode* ret = dummy->next;
        delete dummy;
        return ret;
    }
};

/**
 * using stack
 * time: O(size)
 * space: O(size)
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        stack<ListNode*> stk;
        ListNode* cur = dummy;
        while (cur) {
            stk.push(cur);
            cur = cur->next;
        }
        for (int i = 0; i < n; ++i) {
            stk.pop();
        }
        ListNode* prev = stk.top();
        prev->next = prev->next->next;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};


/**
 * using 2 pointers
 * the `ahead` pointer is ahead of `behind` pointer by `n` nodes
 * when `ahead` reach the tail of the list, `behind` points at the
 * node that is before the node that needs to be deleted.
 * 
 * time: O(size)
 * space: O(1)
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* ahead = dummy;
        ListNode* behind = dummy;

        for(int i = 0; i < n; i++){
            ahead = ahead->next;
        }
        while(ahead->next != nullptr){
            ahead = ahead->next;
            behind = behind->next;
        }

        ListNode* tmp = behind->next;
        behind->next = behind->next->next;

        delete tmp;
        ListNode* ret = dummy->next;
        delete dummy;
        return ret;
    }
};