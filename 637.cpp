#include "header.h"

// time: O(n)
// space: O(logn)
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if(root == nullptr) return vector<double>();

        queue<TreeNode*> qu;
        qu.push(root);
        vector<double> ret;
        while(!qu.empty()){
            int size = qu.size();
            double accumulate = 0.0;
            for(int i = 0; i < size; i++){
                TreeNode* curr = qu.front();
                accumulate += curr->val;
                qu.pop();
                if(curr->left != nullptr) qu.push(curr->left);
                if(curr->right != nullptr) qu.push(curr->right);
            }
            accumulate /= size;
            ret.push_back(accumulate);
        }
        return ret;
    }
};