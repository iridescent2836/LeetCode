#include <header.h>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// hash table
class Solution2 {
public:
    ListNode* detectCycle(ListNode *head) {
        unordered_set<ListNode*> seen;
        ListNode* ptr = head;
        while(ptr != nullptr) {
            if(seen.count(ptr)) 
                return ptr;
            seen.insert(ptr);
            ptr = ptr->next;
        }
        return nullptr;
    }
};

// 2 pointers
// The proof of the algorithm
// can be found in the official LeetCode solution.
class Solution1 {
public:
    ListNode* detectCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr)
            return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr) {

            if(fast->next == nullptr)
                return nullptr;
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow) {
                ListNode* ptr = head;
                while(ptr != slow) {
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
        }

        return nullptr;

    }
};