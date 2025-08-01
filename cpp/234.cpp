#include "header.h"

/**
 * time: O(n)
 * space: O(n)
 * 
 * 存到数组里，然后用双指针
 * 
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> nums;
        ListNode* curr = head;

        while (curr != nullptr) {
            nums.push_back(curr->val);
            curr = curr->next;
        }

        int right = nums.size()-1;
        int left = 0;
        while(left <= right){
            if(nums[left] != nums[right]) return false;
        }
        return true;
    }
};


/**
 * 双指针，将链表后半段倒序排列，再比较是否一致。
 */
class Solution {
public:
    
    bool isPalindrome(ListNode* head) {
        if(head == nullptr) return false;


        ListNode* firstHalfEnd = findFirstHalfEnd(head);
        ListNode* selcondHalfStart = reverseList(firstHalfEnd->next);

        ListNode* p1 = head;
        ListNode* p2 = selcondHalfStart;

        while(p2!=nullptr){
            if(p1->val != p2->val) return false;

            p1 = p1->next;
            p2 = p2->next;
        }

        // 恢复过去链表
        firstHalfEnd->next = reverseList(selcondHalfStart);
        return true;
        
    }

    ListNode* findFirstHalfEnd(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next != nullptr && fast->next->next!=nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* dummy = new ListNode();
        ListNode* curr = head;
        while(curr != nullptr){
            ListNode* next = curr->next;
            curr->next = dummy->next;
            dummy->next = curr;
            curr = next;
        }
        ListNode* ret = dummy->next;
        delete dummy;
        return ret;
    }
};
