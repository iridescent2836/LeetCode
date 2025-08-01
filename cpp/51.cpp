#include "header.h"

class Solution {
public:
    vector<string> tmp_vec;
    vector<vector<string>> ans;
    void helper(vector<int>& cols, vector<int>& diag1, vector<int>& diag2, int row, const int n) {
        if(row == n) {
            ans.push_back(tmp_vec);
            return;
        }
        for(int col = 0; col < n; col++) {
            // one diag is row + col = k, 0 <= k <= 2 * (n - 1)
            // another diag is row - col = k, -(n-1) <= k <= n - 1
            if(cols[col] || diag1[row + col] || diag2[(n -1) + (row - col)]) continue;
            else {
                string tmp;
                for(int k = 0; k < n; k++){
                    if(k != col) tmp.push_back('.');
                    else tmp.push_back('Q');
                }
                tmp_vec.push_back(tmp);
                cols[col] = diag1[row + col] = diag2[(n -1) + (row - col)] = true;
                helper(cols, diag1, diag2, row+1, n);
                cols[col] = diag1[row + col] = diag2[(n -1) + (row - col)] = false;
                tmp_vec.pop_back();
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<int> cols(n, false);
        vector<int> diag1(2*n-1, false);
        vector<int> diag2(2*n-1, false);
        helper(cols, diag1, diag2, 0, n);
        return ans;

    }
};