#include "header.h"

/**
 * for the lowest common ancestor, the left son of it and right son of it must contains
 * p or q, as p and q are different nodes.
 */
class Solution {
public:
    TreeNode* ans;
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == nullptr) return false;
        bool lson = dfs(root->left, p, q);
        bool rson = dfs(root->right, p, q);
        if((lson && rson) || (root->val == p->val) || root->val == q->val)
            ans = root;
        return lson || rson || (root->val == p->val) || (root->val == q->val);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root,p,q);
        return ans;
    }
};


// store all fathers of each node
class Solution {
public:
    unordered_map<int, TreeNode*> father;
    unordered_map<int, bool> visited;
    void dfs(TreeNode* root){
        if(root->left != nullptr){
            father[root->left->val] = root;
            dfs(root->left);
        }
        if(root->right!=nullptr){
            father[root->right->val] = root;
            dfs(root->right);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        father[root->val] = nullptr;

        dfs(root);
        while(p!=nullptr){
            visited[p->val] = true;
            p = father[p->val];
        }
        while(q!=nullptr){
            if(visited[q->val]) return q;
            q = father[q->val];
        }
        return nullptr;
    }

};