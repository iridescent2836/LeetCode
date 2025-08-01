#include "header.h"

// bfs
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if(root == nullptr) return ret;

        queue<TreeNode *> qu;
        qu.push(root);
        while(!qu.empty()){
            int size = qu.size();
            TreeNode* node;
            for(int i = 0; i < size; i++){
                node = qu.front();
                qu.pop();
                if(node->left != nullptr) qu.push(node->left);
                if(node->right != nullptr) qu.push(node->right);
            }
            ret.push_back(node->val);
        }
        return ret;
    }
};

// dfs
class Solution {
public:
    void dfs(TreeNode* root, vector<int>& ans, int depth){
        if(root == nullptr) return;
        // the rightmost node is 
        // the first node that was accessed in this layer
        if(ans.size() == depth) ans.push_back(root->val);
        dfs(root->right,ans,depth+1);
        dfs(root->left,ans,depth+1);
        return;
    }


    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        dfs(root, ans,0);
        return ans;
    }
};