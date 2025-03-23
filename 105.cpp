#include "header.h"


// recursive
class Solution {
public:
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd){
        if(preStart > preEnd || inStart > inEnd) return nullptr;

        // build the current root
        TreeNode* root = new TreeNode(preorder[preStart]);

        // find the position of root in inorder
        int rootVal = root->val;
        int rootIdx = 0;
        for(int i = inStart;i <= inEnd; i++){
            if(inorder[i] == rootVal) {
                rootIdx = i;
                break;
            }
        }

        // recursively build left and right tree
        int leftSize = rootIdx - inStart;
        root->left = helper(preorder, inorder,preStart+1, preStart+leftSize,inStart,rootIdx-1);
        root->right = helper(preorder,inorder,preStart+leftSize+1,preEnd,rootIdx+1,inEnd);

        // return root
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
};

// iteration