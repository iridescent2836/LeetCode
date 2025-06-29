#include "header.h"

/**
 * dp[i][j] = the num of path that could lead to map[i][j]
 * dp[i][j] = dp[i][j-1]+dp[i-1][j]
 * dp[0][j] == 1
 * dp[i][0] == 1
 * 
 * time: O(m*n)
 * space: O(m*n)
 */
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 1 || n == 1) return 1;

        vector<vector<int>> dp(m, vector<int>(n, 1));
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = dp[i][j-1]+dp[i-1][j];
            }
        }
        return dp[m-1][n-1];
    }
};

// optimization, using only one row
// time: O(m*n)
// space: O(n)

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 1 || n == 1) return 1;

        vector<int> dp(n, 1);
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[j] += dp[j-1];
            }
        }
        return dp[n-1];
    }
};

/**
 * use some math. 
 * 要从(0, 0)移动到(m-1, n-1)，机器人需要恰好进行(m-1)次向下移动和(n-1)次向右移动，总共(m + n - 2)次移动。不同的路径对应于这些移动的不同排列顺序。
 * 因此，路径的总数是组合数C(m + n - 2, m - 1)或C(m + n - 2, n - 1)，因为C(a, b) = C(a, a - b)。
 * 组合数的计算公式为：
 * C(a, b) = a! / (b! * (a - b)!)
 * 因此，我们可以直接计算：
 * uniquePaths(m, n) = (m + n - 2)! / ((m - 1)! * (n - 1)!)
 * time: O(min(n, n))
 * space: O(1)
 */
class Solution {
public:
    int uniquePaths(int m, int n) {
        long long result = 1;
        int a = m + n - 2;
        int b = min(m - 1, n - 1);
        for (int i = 1; i <= b; i++) {
            result = result * (a - b + i) / i;
        }
        return (int)result;
    }
};