#include "header.h"

// time: O(n)
// space: O(h = logn)
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;
        TreeNode* left = invertTree(root->left);
        TreeNode* right =  invertTree(root->right);

        root->right = left;
        root->left = right;
        return root;
    }
};

// tail recursion
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;
        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = temp;

        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

// iteration
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;

        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            TreeNode* curr = stk.top();
            stk.pop();

            while(curr != nullptr){
                TreeNode* temp = curr->right;
                curr->right = curr->left;
                curr->left = temp;
                
                if(curr->right != nullptr) stk.push(curr->right);
                curr = curr->left;
            }
        }
        return root;
    }
};


// another version of iteration
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;

        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            TreeNode* curr = stk.top();
            stk.pop();

            // 交换左右子树
            TreeNode* temp = curr->left;
            curr->left = curr->right;
            curr->right = temp;

            // 注意是交换之后再入栈
            if(curr->left) stk.push(curr->left);
            if(curr->right) stk.push(curr->right);
        }
        return root;
    }
};