#include "header.h"

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

// 作者：灵茶山艾府
// 链接：https://leetcode.cn/problems/path-sum-iii/solutions/2784856/zuo-fa-he-560-ti-shi-yi-yang-de-pythonja-fmzo/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;
        unordered_map<long long, int> cnt{{0, 1}};
        auto dfs = [&](this auto&& dfs, TreeNode* node, long long s) {
            if (node == nullptr) {
                return;
            }

            s += node->val;
            // 把 node 当作路径的终点，统计有多少个起点
            ans += cnt[s - targetSum]; // 注意这样写会把 s-targetSum 插入哈希表，介意的话可以特判

            cnt[s]++;
            dfs(node->left, s);
            dfs(node->right, s);
            cnt[s]--; // 恢复现场
        };
        dfs(root, 0);
        return ans;
    }
};

class Solution {
public:

    void dfs( TreeNode* node, long long s, int& ans, unordered_map<long long, int>& cnt, const int targetSum) {
        if(node == nullptr) return;

        s+= node->val;
        ans += cnt[s-targetSum];

        cnt[s]++;
        dfs(node->left, s, ans, cnt, targetSum);
        dfs(node->right, s, ans, cnt, targetSum);
        cnt[s]--;
        
    };

    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;
        unordered_map<long long, int> cnt{{0, 1}};

        dfs(root, 0, ans,cnt, targetSum);
        return ans;
    }
};
