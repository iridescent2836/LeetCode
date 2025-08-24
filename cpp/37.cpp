#include "header.h"

std::vector<std::vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

class Solution {
public:
bool solved = false;
vector<vector<char>> ans;
    void dfs (vector<vector<char>>& board, int row, int col, vector<int>& rows, vector<int>& cols, vector<vector<int>>& grid) {
        if (row == 9) { 
            solved = true; return;
        }
        if (solved) return;  // 如果已经找到解，直接返回
        if (col == 9) {
            dfs(board, row+1, 0, rows, cols, grid);
            return;
        }
        if (board[row][col] != '.'){
            dfs(board, row, col+1, rows, cols, grid);
        }
        else {
            for (int num = 0; num < 9; num++) {
                if (((cols[col] & (1 << num)) == 0) && ((rows[row] & (1 << num)) == 0) && ((grid[row/3][col/3] & (1 << num)) == 0)) {
                    board[row][col] = '1' + num;
                    cols[col] |= (1 << num);
                    rows[row] |= (1 << num);
                    grid[row/3][col/3] |= (1 << num);
                    dfs (board, row, col+1, rows, cols, grid);
                    if(!solved){
                        grid[row/3][col/3] ^= (1 << num);
                        cols[col] ^= (1 << num);
                        rows[row] ^= (1 << num);
                        board[row][col] = '.';
                    }
                }
            }
        }

    }


    void solveSudoku(vector<vector<char>>& board) {
        vector<int> cols(9, 0);
        vector<int> rows(9, 0);
        vector<vector<int>> grid(3, vector<int>(3, 0));
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                grid[i/3][j/3] |= (1 << (board[i][j] - '1'));

                rows[i] |= (1 << (board[i][j] - '1'));
                cols[j] |= (1 << (board[i][j] - '1'));
            }
        }

        dfs(board, 0, 0, rows, cols, grid);
        return;
    }
};

int main() {
    Solution s;
    s.solveSudoku(board);
    return 0;
}