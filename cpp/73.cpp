#include "header.h"

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> row;
        vector<int> col;
        int rows = matrix.size();
        int cols = matrix[0].size();
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(matrix[i][j] == 0){
                    row.push_back(i);
                    col.push_back(j);
                } 
            }
        }
        for(int r: row){
            for(int i = 0; i < cols; i++){
                matrix[r][i] = 0;
            }
        }
        for(int c: col){
            for(int i = 0; i < rows; i++){
                matrix[i][c] = 0;
            }
        }
        return;
    }
};