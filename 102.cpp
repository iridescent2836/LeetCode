#include "header.h"

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return vector<vector<int>>();
        queue<TreeNode*> qu;
        qu.push(root);
        vector<vector<int>> ret;
        while(!qu.empty()){
            int len = qu.size();
            ret.push_back(vector<int>());
            for(int i = 0; i < len; i++){
                TreeNode* node = qu.front();
                qu.pop();
                ret.back().push_back(node->val);
                if(node->left!=nullptr) qu.push(node->left);
                if(node->right!=nullptr) qu.push(node->right);
            }
        }
        return ret;
    }
};