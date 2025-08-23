public class LC64 {
    class SolutionOld {
        public int minPathSum(int[][] grid) {
            int rows = grid.length;        // 行数
            int cols = grid[0].length;     // 列数

            int[][] dp = new int[rows][cols];
            dp[0][0] = grid[0][0];
            for(int i = 1; i < cols; i++) {
                dp[0][i] += dp[0][i-1];
            }

            for(int i = 0; i < rows; i++) {
                for(int j = 0; j < cols; j++) {
                    int up;
                    int left;

                    if(i == 0 && j == 0) continue;

                    if(i == 0) up = Integer.MAX_VALUE;
                    else up = dp[i-1][j];

                    if(j == 0) left = Integer.MAX_VALUE;
                    else left = dp[i][j-1];

                    dp[i][j] = Math.min(up, left) + grid[i][j];
                }
            }


            return dp[rows-1][cols-1];
        }
    }
    class Solution {
        public int minPathSum(int[][] grid) {
            int rows = grid.length;        // 行数
            int cols = grid[0].length;     // 列数
            int[] dp = new int[cols];

            // first row
            dp[0] = grid[0][0];
            for(int i = 1; i < cols; i++) {
                dp[i] = dp[i-1] + grid[0][i];
            }
            
            // process each row
            for(int i = 1; i < rows; i++) {
                // first col
                 dp[0] = dp[0] + grid[i][0];
                // other cols
                for(int j = 1; j < cols; j++) {
                    dp[j] = Math.min(dp[j], dp[j-1]) + grid[i][j];
                }
            }

            return dp[cols-1];
        }
    }
}
