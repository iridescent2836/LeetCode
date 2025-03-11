#include "header.h"

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

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// for detail info, refer to Mr.Lin

class Solution {
public:
    int ans;
    int dfs(TreeNode* node) {
        if(node == nullptr) return 0;
        
        int left_val = dfs(node->left);
        int right_val = dfs(node->right);
        
        ans = max(ans, left_val+right_val+node->val); // the max sum of val that in the path that take node as root. 

        return max(max(left_val+node->val, right_val+node->val),0); // the max val that this node can contribute as a 
                                                                    // node in the path
    }
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        dfs(root);
        return ans;
    }
};