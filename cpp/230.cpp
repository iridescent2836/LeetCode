/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include "header.h"


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // use the property of BST: in-order traversal yields an increasing sequence.
    // we use iteration to do in-order traversal.
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stack;
        TreeNode* ptr = root;

        while(ptr != nullptr || stack.size() > 0) {
            // go left
            while(ptr != nullptr) {
                stack.push(ptr);
                ptr = ptr->left;
            }

            // access
            ptr = stack.top();
            stack.pop();
            k--;
            if(0 == k) {
                break;
            }

            // go right
            ptr = ptr->right;
        }
        return ptr->val;
    }
};