#include "header.h"

class Solution {
public:
    
    bool isValidSudoku(vector<vector<char>>& board) {
        int boardLen = board.size();
        int districtLen = 3;
        int numDistrict = boardLen / districtLen;
        // check each row and col
        for(int i = 0; i < boardLen; i++){
            vector<bool> countRow(9, false);
            vector<bool> countCol(9, false);
            for(int j = 0; j < boardLen; j++){
                if(board[i][j] != '.'){
                    if(countRow[board[i][j] - '1']) return false;
                    countRow[board[i][j] - '1'] = true;
                }
                if(board[j][i]!='.'){
                    if(countCol[board[j][i] - '1']) return false;
                    countCol[board[j][i] - '1'] = true;
                }
            }
        }
        // check each district
        for(int i = 0; i < numDistrict; i++){
            for(int j = 0; j < numDistrict; j++){
                vector<bool> countDistrict(9, false);
                for(int k = 0; k < districtLen; k++){
                    for(int l = 0; l < districtLen; l++){
                        int rowIdx = i * districtLen + k;
                        int colIdx = j * districtLen + l;
                        if(board[rowIdx][colIdx] != '.'){
                            if(countDistrict[board[rowIdx][colIdx] - '1']) return false;
                            countDistrict[board[rowIdx][colIdx] - '1'] = true;
                        }
                    }
                }
            }
        }
        return true;
    }
};