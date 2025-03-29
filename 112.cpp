#include "header.h"

class Solution {
public:
    bool hasPathSum(TreeNode* root, int restSum){
        if(root == nullptr) return false;
        // reached the leaf, check if the path satisfies the requirement. 
        if(root->left == nullptr && root->right == nullptr) return restSum == root->val;
        return hasPathSum(root->left, restSum - root->val) || hasPathSum(root->right, restSum - root->val);
    }
};