#include "header.h"

/**
 * 详细解法见 leetcode 官方解答
 * 
 * 枚举法
 * 枚举高度
 */
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size(); 
        int ans = 0;
        vector<vector<int>> row(rows, vector<int>(cols, 0)); // row[i][j] 是 mat[i][j] 向左延伸最长的长度
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (j == 0 || mat[i][j] == 0) row[i][j] = mat[i][j];
                else row[i][j] = row[i][j-1] + 1;

                int curr = row[i][j];
                for (int k = i; k >= 0; --k) {
                    curr = min(curr, row[k][j]);
                    if (curr == 0) break;
                    ans += curr;
                }
            }
        }
        return ans;
    }
};



/**
 * 单调栈
 * 
 * 没看懂
 */
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int cols = mat[0].size();
        vector<int> heights(cols, 0);
        int ans = 0;

        for (const auto& row: mat) {
            for (int i = 0; i < cols; ++i) {
                heights[i] = row[i] == 0 ? 0 : heights[i] + 1;
            }

            stack<vector<int>> stk;
            stk.push({-1, 0, -1});
            for (int i = 0; i < cols; ++i) {
                int h = heights[i];
                while (stk.top()[2] >= h) {
                    stk.pop();
                }

                auto& top = stk.top();
                int j = top[0];
                int prev = top[1];
                int cur = prev + (i - j) * h;
                stk.push({i, cur, h});
                ans += cur;
            }

        }
        return ans;
    }
};