#include "header.h"

// clever recursion. 
class Solution {
public:
    bool dfs(TreeNode* root, int64_t lower, int64_t upper){
        if(root == nullptr) return true;
        if(root->val <= lower || root->val >= upper) return false;

        return dfs(root->left, lower, root->val) && dfs(root->right, root->val, upper);
    }
    bool isValidBST(TreeNode* root) {

        return dfs(root,INT64_MIN, INT64_MAX);
    }
};