#include "header.h"

// awful shity code. no comment. 
class Solution {
public:
    int paint(vector<vector<int>>& grid, int x, int y){
        if(0 <= x && x < grid.size() && 0 <= y && y < grid[0].size()){
            if(grid[x][y] == 0 || grid[x][y] == 2) return 0;
            grid[x][y] = 2;
            return 1;
        }
        return 0;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int isChanged = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;
        do{
            isChanged = 0;
            count++;
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < cols; j++){
                    if(grid[i][j] == 2){
                        isChanged += paint(grid, i-1, j);
                        isChanged += paint(grid, i, j-1);
                        isChanged += paint(grid, i, j+1);
                        isChanged += paint(grid, i+1, j);
                    }
                }
            }
        } while(isChanged!=0);
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return count;
    }
};

/**
 * use BFS you dumb ass. 
 * 
 */
class Solution {
public:
    void paint(vector<vector<int>>& grid, int x, int y, queue<pair<int, int>>& qu, bool & isChanged){
        if(0 <= x && x < grid.size() && 0 <= y && y < grid[0].size()){
            
            if(grid[x][y] == 0 || grid[x][y] == 2) return;
            
            grid[x][y] = 2;
            isChanged = true;
            qu.push({x,y});
        }
        return;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int count = 0;
        queue<pair<int, int>> qu;
        int rows = grid.size();
        int cols = grid[0].size();
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 2) qu.push({i, j});
            }
        }
        while(!qu.empty()){
            int n = qu.size();
            bool isChanged=false;
            for(int i = 0; i < n; i++){
                auto curr = qu.front();
                qu.pop();
                int x = curr.first;
                int y = curr.second;
                paint(grid, x, y-1, qu, isChanged);
                paint(grid, x-1, y, qu, isChanged);
                paint(grid, x, y+1, qu, isChanged);
                paint(grid, x+1, y, qu, isChanged);

            }
            if(isChanged) count++;
        }
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return count;
    }
};