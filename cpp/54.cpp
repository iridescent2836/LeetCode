#include "header.h"

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int top = 0, bottom = rows - 1;
        int left = 0, right = cols - 1;
        
        int size = rows * cols;
        vector<int> ans(size, 0);
        int len = 0;

        while(len < size) {
            // left to right
            for(int i = left; i <= right && len < size; i++, len++) {
                ans[len] = matrix[top][i];
            }
            // top to bottom
            for(int i = top + 1; i < bottom && len < size; i++, len++) {
                ans[len] = matrix[i][right];
            }
            // right to left
            for(int i = right; i > left && len < size; i--, len++) {
                ans[len] = matrix[bottom][i];
            }
            // bottom to top
            for(int i = bottom; i > top && len < size; i--, len++) {
                ans[len] = matrix[i][left];
            }
            top++;
            bottom--;
            left++;
            right--;
        }
        
        return ans;
    }
};