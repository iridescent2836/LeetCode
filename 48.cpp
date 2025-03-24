#include "header.h"

// invincible, i am genius
// for detailed explanation, please refer to https://leetcode.cn/problems/rotate-image/, 
// which is published by myself. 
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int layer = n / 2;
        // rotate each layer
        for(int i = 0; i < layer; i++){
            int rotatePerLayer = n - (i<<1) - 1; // the sets of element that need to be rotated
            // rotate each element
            for(int j = 0; j < rotatePerLayer; j++){
                swap(matrix[i][i+j],matrix[i+j][i+rotatePerLayer]);
                swap(matrix[i][i+j], matrix[i+rotatePerLayer][i+rotatePerLayer-j]);
                swap(matrix[i][i+j], matrix[i+rotatePerLayer-j][i]);
            }
        }
        return;
    }
};