#include "header.h"

// O(n * m) time complexity, O(n * m) space complexity

// bfs
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int,int>> q;
        int rows = board.size();
        int cols = board[0].size();
        for(int i = 0; i < cols; i++){
            if(board[0][i] == 'O') q.push({0,i});
            if(board[rows-1][i] == 'O') q.push({rows-1, i});
        }
        for(int i = 1; i < rows-1; i++){
            if(board[i][0] == 'O') q.push({i,0});
            if(board[i][cols-1] == 'O') q.push({i,cols-1});
        }
        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();
            int i = curr.first;
            int j = curr.second;
            // clever, use the alternative character 'A' to represent the edge area. 
            if(board[i][j] == 'O'){
                board[i][j] = 'A';
                if(i > 0){
                    if(board[i-1][j] == 'O')
                        q.push({i-1,j});
                }
                if(i < rows-1){
                    if(board[i+1][j] == 'O')
                        q.push({i+1,j});
                }
                if(j > 0){
                    if(board[i][j-1] == 'O')
                        q.push({i,j-1});
                }
                if(j < cols-1){
                    if(board[i][j+1] == 'O')
                        q.push({i,j+1});
                }
            }
        }
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(board[i][j] == 'A') board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }
        
    }
};


// dfs

// O(n * m) time complexity, O(n * m) space complexity
class Solution {
public:
    int rows;
    int cols;
    void dfs(vector<vector<char>>& board, int i, int j){
        if(i < 0 || j < 0 || i >= rows || j >= cols || board[i][j] != 'O') return;
        board[i][j] = 'A';
        dfs(board,i-1,j);
        dfs(board,i+1,j);
        dfs(board,i,j-1);
        dfs(board,i,j+1);
        return;
    }

    void solve(vector<vector<char>>& board) {
        queue<pair<int,int>> q;
        rows = board.size();
        cols = board[0].size();
        for(int i = 0; i < cols; i++){
            dfs(board,0,i);
            dfs(board,rows-1,i);

        }
        for(int i = 1; i < rows-1; i++){
            dfs(board,i,0);
            dfs(board,i,cols-1);
        }
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(board[i][j] == 'A') board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }
    }
};