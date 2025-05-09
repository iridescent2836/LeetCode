#include "header.h"

/**
 * Simple BFS
 * 
 * clever by using `reachTime[row][col] + 1 < reachTime[new_row][new_col]` 
 * to replace the `visited` matrix. And it's crutial to determine that 
 * the time is minimum.
 * 
 * time: O(rows * cols)
 * space: same as time
 */
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        vector<pair<int, int>> directions{{-1,0}, {1,0},{0,-1},{0,1}};

        int rows = moveTime.size();
        int cols = moveTime[0].size();

        vector<vector<int>> reachTime(rows, vector<int>(cols, INT32_MAX));

        queue<pair<int, int>> qu;
        qu.push({0,0});
        reachTime[0][0] = 0;
        // bfs
        while(!qu.empty()){
            pair<int, int> curr_pos = qu.front();
            int row = curr_pos.first;
            int col = curr_pos.second;
            qu.pop();
            // check each adjacent node
            for(auto& direction: directions){
                int new_row = row + direction.first;
                int new_col = col + direction.second;
                // if the index is legal and the node is reachable
                if (0 <= new_row && new_row < rows && 0 <= new_col && new_col < cols 
                    && reachTime[row][col] + 1 < reachTime[new_row][new_col]){
                    reachTime[new_row][new_col] = max(reachTime[row][col] + 1,
                                                      moveTime[new_row][new_col] + 1);
                    qu.push({new_row, new_col});
                }
            }
        }
        return reachTime[rows-1][cols-1];
    }
};

/**
 * dp version. I know it's incorrect, but I just want to try it out. 
 * And to sharpen my skills of using dp. 
 * 
 * dp[i][j] = max(moveTime[i-1][j-1]+1, min(dp[i-1][j]+1, dp[i][j-1]+1))
 * 
 * dp[1][1] = 0
 * 
 * rightful dp, but dp is not correct. 
 * I don't know what I am talking about, lol. 
 */

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size();
        int n = moveTime[0].size();

        vector<vector<int>> dp(m+2,vector<int>(n+2,INT32_MAX-2));
        dp[1][1] = 0;

        for(int i = 1; i < m+1; i++){
            for(int j = 1; j < n+1; j++){
                if(i == 1 && j == 1) continue;
                dp[i][j] = max(moveTime[i-1][j-1]+1, min(dp[i-1][j]+1, dp[i][j-1]+1));
            }
        }

        return dp[m][n];
    }
};
