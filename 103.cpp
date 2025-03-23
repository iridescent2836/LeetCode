#include "header.h"


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr) return vector<vector<int>>();
        queue<TreeNode*> qu;
        qu.push(root);
        bool FromLeft = true;
        vector<vector<int>> ret;
        while(!qu.empty()){
            int size = qu.size();
            vector<int>temp;
            for(int i = 0; i < size; i++){
                TreeNode* node = qu.front();
                temp.push_back(node->val);
                qu.pop();
                if(node->left!=nullptr) qu.push(node->left);
                if(node->right!=nullptr) qu.push(node->right);                
            }
            if(!FromLeft) reverse(temp.begin(), temp.end());
            FromLeft = !FromLeft;
            ret.emplace_back(temp);
        }
        return ret;
    }
};