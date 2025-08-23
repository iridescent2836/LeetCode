#include "header.h"

// dfs
class Solution {
public:
    void dfs(TreeNode* root, vector<int>& ans, int depth){
        if(root == nullptr) return;
        // the rightmost node is 
        // the first node that was accessed in this layer
        if (ans.size() == depth) ans.push_back(root->val);
        dfs(root->right, ans, depth+1);
        dfs(root->left, ans, depth+1);
    }


    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        dfs(root, ans,0);
        return ans;
    }
};

// bfs
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return vector<int>();
        vector<int> ans;
        queue<TreeNode*> q;

        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* curr = q.front();
                q.pop();
                if (i == 0) ans.push_back(curr->val);
                if (curr->right != nullptr) q.push(curr->right);
                if (curr->left != nullptr) q.push(curr->left);
            }
        }

        return ans;
    }
};


