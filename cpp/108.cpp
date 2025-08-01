#include "header.h"

class Solution {
public:
    TreeNode* helper(const vector<int>& nums, int start, int end){
        if(start > end){
            return nullptr;
        }

        int mid = (start + end) >> 1;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(nums, start, mid-1);
        root->right = helper(nums, mid+1, end);
        return root;
    }


    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};