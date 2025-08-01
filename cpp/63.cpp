#include "header.h"
/**
 * dp[i][j] = the number of paths that can reach gird[i][j]
 * if(grid[i][j] is not obstacle)
 *  dp[i][j] = dp[i-1][j]+dp[i][j-1]
 * else
 *  dp[i][j] = 0
 * 
 * time: O(nm)
 * space: O(nm)
 */

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();

        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        int isObstacle = 1;
        for(int i = 0; i < cols; i++){
            if(i == 0) dp[0][i] = !obstacleGrid[0][i];
            else if(!obstacleGrid[0][i]) dp[0][i] = dp[0][i-1]; // didn't encounter obstacle
            else dp[0][i] = 0; // encounter obstacle
        }
        for(int i = 0; i < rows; i++){
            if(i == 0) dp[i][0] = !obstacleGrid[i][0];
            else if(!obstacleGrid[i][0]) dp[i][0] = dp[i-1][0];
            else dp[i][0] = 0;
        }
        for(int i = 1; i < rows; i++){
            for(int j = 1; j < cols; j++){
                // encounter obstacle
                if(obstacleGrid[i][j])
                    dp[i][j] = 0;
                // didn't
                else
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[rows-1][cols-1];
    }
};

/**
 * an optimized version
 * a clever optimization
 * 
 * time: O(nm)
 * space: O(m)
 */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<int> dp(m,0);

        dp[0] = (obstacleGrid[0][0] == 0);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(obstacleGrid[i][j] == 1){
                    dp[j] = 0;
                }
                else if(j>=1){
                    dp[j] += dp[j-1];
                }
            }
        }
        return dp[m-1];
    }
};