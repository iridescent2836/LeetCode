#include "header.h"

/**
 * more space for less time
 * we construct a vector that stores the tree in order
 * so the next() and hasNext() would be O(1) time complexity
 * time: O(n) for constructing, O(1) for next() and hasNext()
 * space: O(n)
 */
class BSTIterator {
public:
    vector<int> in_order_traverse;
    int index = 0;
    int len;
    BSTIterator(TreeNode* root) {
        in_order_traverse.push_back(-1);
        inOrder(root);
        len = in_order_traverse.size();
    }
    void inOrder(TreeNode* root){
        if(root == nullptr) return;
        inOrder(root->left);
        in_order_traverse.push_back(root->val);
        inOrder(root->right);
        return;
    }
    int next() {
        index++;
        return in_order_traverse[index];

    }
    
    bool hasNext() {
        if(index + 1 == len) return false;
        else return true;
    }
};

/**
 * use iteration instead of recursive method.
 * maintaining a stack that stores the current state of in order tranverse
 * when going to next, the stack gos to the next state
 */


class BSTIterator {
private:
    TreeNode* curr;
    stack<TreeNode*> stk;
public:
    BSTIterator(TreeNode* root): curr(root) {}
    
    int next() {
        // go left
        while(curr != nullptr){
            stk.push(curr);
            curr = curr->left;
        }
        // access the current node
        curr = stk.top();
        stk.pop();
        int ret = curr->val;
        // go right
        curr = curr->right;
        return ret;
    }
    
    bool hasNext() {
        return curr != nullptr || !stk.empty();
    }
};
