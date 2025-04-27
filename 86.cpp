#include "header.h"


/**
 * time: O(n)
 * space: O(1)
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* dummy = new ListNode(0,head);


        ListNode* pre = dummy;
        // find the 1st node before the node whose value is greater or equal than x. 
        while( pre->next != nullptr && pre->next->val < x){
            pre = pre->next;
        }

        // if all node's value is smaller than x, or the Node whose value is
        // greater or equal than x is at the tail of the list, then just return the
        // head;
        if(pre->next == nullptr){
            delete dummy;
            return head;
        } 
        ListNode* preCurr = pre;
        ListNode* curr = pre->next;
        while(curr != nullptr){
            if(curr->val < x){
                preCurr->next = curr->next;
                curr->next = pre->next;
                pre->next = curr;
                pre = pre->next;
                curr = preCurr->next;
            } else {
                curr = curr->next;
                preCurr = preCurr->next;
            }
        }

        ListNode* ret = dummy->next;
        delete dummy;
        return ret;
    }
};

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    Solution s;
    s.partition(head,3);
}