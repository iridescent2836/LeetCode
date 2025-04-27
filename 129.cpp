#include "header.h"


class Solution {
public:
    void dfs(TreeNode* root, int num, int& ans){
        if(root->left == nullptr && root->right == nullptr){
            ans += num * 10 + root->val;
            return;
        }

        int temp = num*10+root->val;
        if(root->left != nullptr) dfs(root->left, temp, ans);
        if(root->right != nullptr) dfs(root->right, temp, ans);
    }
    int sumNumbers(TreeNode* root) {
        if(root == nullptr) return 0;
        int num = 0;
        int ans = 0;
        dfs(root, num, ans);
        return ans;
    }
};

