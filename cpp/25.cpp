#include "header.h"

class Solution {
public:
    void printList(ListNode* head){
        while(head!=nullptr){
            cout << head->val << ' ';
            head = head->next;
        }
        cout << endl;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr) return nullptr;
        if(k==1) return head;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* curr = dummy;
        while(curr != nullptr){
            ListNode* tail = curr;
            int i = 0;
            while( i < k && tail != nullptr){
                tail = tail->next;
                i++;
            }
            // there are fewer than k nodes ramaining, or tail is null
            // in case k become null right when i == k
            if(i!=k || tail == nullptr) break;

            // reverse the list(curr,tail];
            for(i = 0; i < k-1; i++){
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                temp->next = tail->next;
                tail->next = temp;

            }
            
            // move curr
            i = 0;
            while(i < k && curr != nullptr){
                curr = curr->next;
                i++;
            }

        }
        ListNode* ret = dummy->next;
        delete dummy;
        return ret;
    }
};


int main(){
    ListNode* head = new ListNode(1);
    ListNode* curr = head;
    for(int i = 0; i < 4; i++){
        curr->next = new ListNode(i+2);
        curr = curr->next;
    }
    Solution s;
    s.printList(s.reverseKGroup(head, 2));

    return 0;
}