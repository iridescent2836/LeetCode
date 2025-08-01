#include "header.h"

class Solution {
public:
    int rows;
    int cols;

    void dfs(const vector<vector<char>>& grid, int row, int col, vector<vector<bool>>& visited){
        if(grid[row][col] == '0' || visited[row][col]) return;

        visited[row][col] = true;
        if(row < rows-1)
            dfs(grid, row+1, col, visited);
        if(row > 0)
            dfs(grid, row-1, col, visited);
        
        if(col < cols-1)
            dfs(grid, row, col+1, visited);
        if(col > 0)
            dfs(grid, row, col-1, visited);
        
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int ret = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    ret++;
                    dfs(grid, i, j, visited);
                }
            }
        }
        return ret;
    }
};

// using gird instead of creating a new `visitied` matrix. 
class Solution {
public:
    int rows;
    int cols;

    void dfs(vector<vector<char>>& grid, int row, int col){
        if(grid[row][col] == '0' || grid[row][col] == '2') return;

        grid[row][col] = '2';
        if(row < rows-1)
            dfs(grid, row+1, col);
        if(row > 0)
            dfs(grid, row-1, col);
        
        if(col < cols-1)
            dfs(grid, row, col+1);
        if(col > 0)
            dfs(grid, row, col-1);
        
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int ret = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == '1'){
                    ret++;
                    dfs(grid, i, j);
                }
            }
        }
        return ret;
    }
};