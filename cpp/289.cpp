#include "header.h"

class Solution {
private:
    int rows;
    int cols;
public:
    int countLives(vector<vector<int>>& board, int i, int j){
        int lives = 0;
        if(i > 0){
            lives += board[i-1][j];
            if(j > 0) lives += board[i-1][j-1];
        }
        if(i < rows-1){
            lives += board[i+1][j];
            if(j < cols-1) lives += board[i+1][j+1];
        }
        if(j > 0){
            lives += board[i][j-1];
            if(i < rows-1) lives += board[i+1][j-1]; 
        }
        if(j < cols-1){
            lives += board[i][j+1];
            if(i > 0) lives += board[i-1][j+1];
        }
    }

    void gameOfLife(vector<vector<int>>& board) {
        rows = board.size();
        cols = board[0].size();
        vector<vector<int>> newBoard = board;
        int lives;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                lives = countLives(board, i, j);
                if(board[i][j]){
                    if(lives < 2 || lives > 3) newBoard[i][j] = 0;
                }
                else if(lives == 3) newBoard[i][j] = 1;
            }
        }

        board = newBoard;
    }
};