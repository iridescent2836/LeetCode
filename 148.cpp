#include "header.h"

/**
 * a stupid but workable method
 * 
 * space: O(1)
 * time: O(n^2 + n)
 */
class Solution1 {
public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* dummy = new ListNode();
        ListNode* dummyOld = new ListNode(0,head);
        ListNode* MaxNode;
        ListNode* PreMaxNode;
        ListNode* curr = head;
        ListNode* pre;
        int size = 0;
        while(curr != nullptr){
            size++;
            curr = curr->next;
        }
        for(int i = 0; i < size; i++){
            curr = dummyOld->next;
            pre = dummyOld;
            MaxNode = dummyOld->next;
            PreMaxNode = dummyOld;
            while(curr != nullptr){
                if(curr->val > MaxNode->val){
                    MaxNode = curr;
                    PreMaxNode = pre;
                }
                curr = curr->next;
                pre = pre->next;
            }
            PreMaxNode->next = MaxNode->next;
            MaxNode->next = dummy->next;
            dummy->next = MaxNode;
        }
        delete dummyOld;
        ListNode* ret = dummy->next;
        delete dummy;
        return ret;
    }
};

/**
 * merge sort
 * 
 * space: O(logn): The cost of system stack
 * time: O(nlogn)
 * 
 * ListNode* fast = head;
 * ListNode* slow = head;
 * this would cause BUG!!!
 * 比如这个链表：
 * [1] -> [2]
 * 运行时：
 * 初始链表：[1] -> [2]
 * slow 最终指向 [2]（不是中点的前一位）
 * head2 = slow->next 为 nullptr
 * 然后递归调用 sortList(head) 时，head 仍然是 [1] -> [2]，因为 slow->next = nullptr 并没有切断 [1] 和 [2]，此时 slow == head->next
 * 尽管你写了 slow->next = nullptr，但那是原链表第二个节点之后的节点为 null，而 sortList(head) 的 head 仍然是 [1] -> [2]
 * 所以这时候会不断地递归 sortList([1] -> [2])，死循环。
 */

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast!=nullptr && fast->next!=nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* head2 = slow->next;
        slow->next = nullptr;
        ListNode* left = sortList(head);
        ListNode* right = sortList(head2);
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        while(left != nullptr && right != nullptr){
            if(left->val < right->val){
                curr->next = left;
                left = left->next;

            } else {
                curr->next = right;
                right = right->next;
            }
            curr = curr->next;
            curr->next = nullptr;
        }
        if(left!=nullptr){
            curr->next = left;
        }
        if(right!=nullptr){
            curr->next = right;
        }
        ListNode* ret = dummy->next;
        delete dummy;
        return ret;
    }
};

