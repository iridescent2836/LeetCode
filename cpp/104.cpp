#include "header.h"
#include <queue>
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


// dfs
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

// 迭代 bfs
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int depth = 1;
        queue<TreeNode*> q;
        q.push(root);


        // access
        while(!q.empty()){
            int size = q.size();
            TreeNode* ptr;
            for(int i = 0; i < size; i++){
                ptr = q.front();
                q.pop();
                if(ptr->left != nullptr) q.push(ptr->left);
                if(ptr->right != nullptr) q.push(ptr->right);

            }
            depth++;
        }
        return depth;


    }
};

//迭代， 前序，dfs
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int max_depth = 1;
        stack<pair<TreeNode*,int>> s;

        s.push({root, max_depth});
        while(!s.empty()){
            // access
            auto [node, depth] = s.top();
            s.pop();
            max_depth = max(depth, max_depth);
            // 先压入右子节点，保证左子节点先被处理

            if (node->right) s.push({node->right, depth + 1});
            if (node->left) s.push({node->left, depth + 1});
        }

        return max_depth;
    }
};