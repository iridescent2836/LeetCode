#include "header.h"
#include <unordered_set>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 2 pointers
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr)
            return false;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(slow != fast) {

            if(fast == nullptr || fast->next == nullptr)
                return false;
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};

// hash table
class Solution2 {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> seen;
        ListNode* ptr = head;
        while(ptr != nullptr) {
            if(seen.count(ptr)) 
                return true;
            seen.insert(ptr);
            ptr = ptr->next;
        }
        return false;
    }
};