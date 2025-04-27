#include "header.h"

class Solution {
public:
    // dfs
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

// use the feature of full binary tree and binary search
// for detailed explanation, please refer to the official leetcode solution. 
class Solution {
public:
    
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        int level = 0;
        // go to the buttom of the tree, count the number of levels.
        TreeNode* curr = root;
        while(curr->left!=nullptr){
            level++;
            curr = curr->left;
        }
        // the upper and lower bounds of the number of nodes
        int low = 1 << level;
        int high = (1 << (level + 1)) -1;
        while(low < high){
            int mid = (high - low + 1) / 2 + low;
            if(exists(root, level, mid)){
                low = mid;
            } else{
                high = mid - 1;
            }
        }
        return low;
    }
    bool exists(TreeNode* root, int level, int k) {
        int bits = 1 << (level - 1); // 用于位操作确定路径
        TreeNode* node = root;
        while (bits > 0) {
            if ((k & bits) == 0) {
                node = node->left;  // 当前位为0，向左走
            } else {
                node = node->right; // 当前位为1，向右走
            }
            bits >>= 1; // 右移一位，处理下一个比特位
        }
        return node != nullptr;
    }
};

