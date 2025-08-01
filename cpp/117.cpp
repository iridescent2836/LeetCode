#include "header.h"
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};



class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr)
            return root;


        queue<Node*> q;
        q.push(root);
        int numOfThisLevel = 1;
        int numOfNextLevel = 0;
        while(!q.empty()){
            int qSize = q.size();
                Node* node = q.front();
                q.pop();
                numOfThisLevel--;

                if(numOfThisLevel != 0){ 
                    node->next = q.front();
                }
                else{ 
                    node->next = nullptr;
                }



                if(node->left!=nullptr){
                    numOfNextLevel++; 
                    q.push(node->left);
                }
                if(node->right!=nullptr){
                    numOfNextLevel++; 
                    q.push(node->right);
                }

                if(numOfThisLevel == 0){
                    numOfThisLevel = numOfNextLevel;
                    numOfNextLevel = 0;
                }
            
        }
        return root;
    }
};


// O(1) space complexity
class Solution {
    public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }

        Node* head = root;

        while(head!=nullptr){
            Node virture;
            Node* nextHead = &virture;
            Node* nextCurr = nextHead;
            
            for(;head != nullptr; head = head->next){
                if(head->left!= nullptr){
                    nextCurr->next = head->left;
                    nextCurr = nextCurr->next;
                }
                if(head->right!= nullptr){
                    nextCurr->next = head->right;
                    nextCurr = nextCurr->next;
                }
            }
            head = nextHead->next;
        }
        return root;
    }
};