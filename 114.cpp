#include "header.h"

/**
 * stupid but workable method
 * time: O(n)
 * space: O(n)
 */
class Solution {
public:
    vector<TreeNode*> preOrderTraverse;
    void preOrder(TreeNode* root){
        if(root == nullptr) return;

        preOrderTraverse.push_back(root);
        preOrder(root->left);
        preOrder(root->right);
        return;
    }
    void flatten(TreeNode* root) {
        if(root == nullptr) return;

        preOrder(root);

        int size = preOrderTraverse.size();
        for(int i = 1; i < size; i++){
            TreeNode* prev = preOrderTraverse[i-1];
            TreeNode* curr = preOrderTraverse[i];

            prev->left = nullptr;
            prev->right = curr;
        }
        
        return;
    }
};