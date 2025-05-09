#include "header.h"
#include <functional>

class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        vector<bool> cols(n, false);          // 列是否被占
        // 2 lines 
        vector<bool> diag1(2 * n - 1, false); // 45度对角线（r + c）
        vector<bool> diag2(2 * n - 1, false); // 135度对角线（r - c + n - 1）

        function<void(int)> dfs = [&](int row) {
            if (row == n) {
                count++;
                return;
            }
            for (int col = 0; col < n; ++col) {
                // position illegal
                if (cols[col] || diag1[row + col] || diag2[row - col + n - 1])
                    continue;
                cols[col] = diag1[row + col] = diag2[row - col + n - 1] = true;
                dfs(row + 1);
                cols[col] = diag1[row + col] = diag2[row - col + n - 1] = false;
            }
        };

        dfs(0);
        return count;
    }
};


class Solution {
public:
    void helper(int row, int& ret, vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2, const int size) {
        if (row == size) {
            ret++;
        }

        int count = 0;
        for (int col = 0; col < size; col++) {
            if (cols[col] || diag1[row + col] || diag2[row - col + size - 1])
                continue;

            // 标记当前位置被占
            cols[col] = diag1[row + col] = diag2[row - col + size - 1] = true;

            helper(row + 1, ret, cols, diag1, diag2, size);

            // 回溯取消标记
            cols[col] = diag1[row + col] = diag2[row - col + size - 1] = false;
        }

    }

    int totalNQueens(int n) {
        int ret = 0;
        vector<bool> cols(n, false);
        vector<bool> diag1(2 * n - 1, false);
        vector<bool> diag2(2 * n - 1, false);

        helper(0, ret, cols, diag1, diag2, n);
        return ret;
    }
};
    
    