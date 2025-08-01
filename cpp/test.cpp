#include "header.h"


// insertion sort

struct Node {
    int value;
    Node* next;
    Node(): value(0), next(nullptr) {}
    Node(int _value): value(_value), next(nullptr) {}
};

class Solution {
private:
    Node* head;
    int k;
public:

    void pringList() {
        Node* curr = head->next;
        while(curr != nullptr) {
            cout << curr->value << ' ';
            curr = curr->next;
        }
        cout << '\n';
        return;
    }
    void insertNode(Node* node) {
        Node* curr = head;
        while(curr->next != nullptr) {
            if(curr->next->value > node->value) {
                node->next = curr->next;
                curr->next = node;
                return;
            }
        }

        // node is the larget number
        curr->next = node;

        pringList();
        return;
    }

    bool deleteNode(int value) {
        Node* pre = head;
        while(pre->next != nullptr) {
            if(pre->next->value == value) {
                Node* toDelete = pre->next;
                pre->next = toDelete->next;
                delete toDelete;
                return true;
            }
        }
        return false;
    }

    double findMedian() {
        if(k&1) {
            int step = k / 2 + 1;
            Node* curr = head;
            for(int i = 0; i < step; i++) {
                curr = curr->next;
            }
            return curr->value;
        } else {
            int step = k / 2;
            Node* curr = head;

            for(int i = 0; i < step; i++) {
                curr = curr->next;
            }

            return (curr->value + curr->next->value) / 2.0;
        }
    }
    
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        head = new Node();
        this->k = k;

        int len = nums.size();
        for(int i = 0; i < k; i++) {
            Node* node = new Node(nums[i]);
            insertNode(node);
        }

        vector<double> ans;
        ans.push_back(findMedian());

        for(int i = k; i < len ; i++) {
            Node* node = new Node(nums[i]);
            insertNode(node);
            deleteNode(nums[i - k]);
            ans.push_back(findMedian());

        }
        return ans;
    }
};


int main() {

    vector<int> nums {1,3,-1,-3,5,3,6,7};
    int k = 3;

    Solution s;
    s.medianSlidingWindow(nums, k);

    return 0;
}