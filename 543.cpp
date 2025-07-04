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
class Solution {
public:
    int longestRoute;
    int dfs(TreeNode* root){
        if(root==nullptr) return 0;
        
        int leftHeight = dfs(root->left);
        int rightHeight = dfs(root->right);

        longestRoute = max(longestRoute, leftHeight+rightHeight);

        // return the height of the tree
        return 1 + max(leftHeight, rightHeight);

    }
    int diameterOfBinaryTree(TreeNode* root) {
        longestRoute = 0;
        dfs(root);
        return longestRoute;
    }
};