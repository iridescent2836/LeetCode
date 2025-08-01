public class LC790 {
    static final int MOD = 1000000007;

    public int numTilings(int n) {
        int[][] dp = new int[n + 1][4];
        dp[0][3] = 1;
        for (int i = 1; i <= n; i++) {
            dp[i][0] = dp[i - 1][3];
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
            dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
            dp[i][3] = (((dp[i - 1][0] + dp[i - 1][1]) % MOD + dp[i - 1][2]) % MOD + dp[i - 1][3]) % MOD;
        }
        return dp[n][3];
    }
}


/**
 * 矩阵快速幂
 * 
 * 首先我们可以构建这样一个递推关系：
 *
 * [ 1  1 ]   [ f(n)     ]   =   [ f(n) + f(n-1) ]   =   [ f(n+1) ]
 * [ 1  0 ] × [ f(n-1)   ]       [     f(n)     ]       [   f(n)  ]
 *
 * 因此：
 *
 * [ f(n+1) ]   =   [ 1  1 ]^n × [ f(1) ]
 * [   f(n) ]       [ 1  0 ]     [ f(0) ]
 *
 * 令：
 *
 * M = [ 1  1 ]
 *     [ 1  0 ]
 */