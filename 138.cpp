#include "header.h"

#include <stdio.h>

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// easy version
// time: O(n)
// space: O(n)
class Solution {
public:

    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        unordered_map<Node*, Node*> old2New;
        Node* newHead = new Node(head->val);

        Node* curr = head;
        Node* newCurr = newHead;
        old2New[head] = newHead;
        while(curr->next!=nullptr){
            newCurr->next = new Node(curr->next->val);
            curr = curr->next;
            newCurr = newCurr->next;
            old2New[curr] = newCurr;
        }

        curr = head;
        newCurr = newHead;
        while(curr != nullptr){
            if(newCurr->random!=nullptr){
                newCurr->random = old2New[curr];
            }
            curr = curr->next;
            newCurr = newCurr->next;
        }
        return newHead;
    }
};

// clever version, detail explanation please refer to leetcode official solution.
// time: O(n)
// space: O(1)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        for(Node* curr = head; curr != nullptr; curr = curr->next->next){
            Node* newCurr = new Node(curr->val);
            newCurr->next = curr->next;
            curr->next = newCurr;
        }
        for(Node* curr = head; curr != nullptr; curr = curr->next->next){
            Node* newCurr = curr->next;
            newCurr->random = (curr->random == nullptr) ? nullptr : curr->random->next;
        }

        Node* newHead = head->next;
        for(Node* curr = head; curr != nullptr; curr = curr->next){
            Node* newCurr = curr->next;
            curr->next = curr->next->next;
            newCurr->next = (newCurr->next==nullptr)? nullptr: newCurr->next->next;
        }
        return newHead;
    }
};
    
