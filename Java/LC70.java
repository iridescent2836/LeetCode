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
 * 
 * 只需要快速算出M^n即可
 * 我们用快速幂算法实现
 * 
 * 
 */

public class LC70 {
    public class Solution {
        public int climbStairs(int n) {
            int[][] q = {{1, 1}, {1, 0}};
            int[][] res = pow(q, n);
            return res[0][0];
        }

        // 快速幂算法
        /**
         * 
         * https://www.bilibili.com/video/BV1V8DmYxEPV/?spm_id_from=333.1387.favlist.content.click&vd_source=95e8460b422bb7a24129e80ee6a2d2ad
         * 快速幂算法说明：
         * 假设我们要求 a^n，可以将 n 用二进制表示，例如 n = 51（二进制为 110011）。
         * 快速幂的核心思想是：每一位为 1 时，将当前底数的幂累乘到结果上。
         * 具体步骤如下：
         * 1. 初始化结果为 1（或单位矩阵）。
         * 2. 从低位到高位遍历 n 的每一位：
         *    - 如果当前位为 1，则将当前底数累乘到结果上。
         *    - 每次循环底数自乘（a = a * a），指数右移一位（n >>= 1）。
         * 3. 最终得到 a^n。
         * 
         * 例如 n = 51（二进制 110011）：
         * a^51 = a^(32) * a^(16) * a^(2) * a^(1)
         * 只在 n 的二进制为 1 的位上累乘。
         * 
         * 该算法可以将幂运算的时间复杂度从 O(n) 降低到 O(log n)，
         * 并且同样适用于矩阵幂运算。
         */
        public int[][] pow(int[][] a, int n) {
            int[][] ret = {{1, 0}, {0, 1}};
            while (n > 0) {
                if ((n & 1) == 1) {
                    ret = multiply(ret, a);
                }
                n >>= 1;
                a = multiply(a, a);
            }
            return ret;
        }

        public int[][] multiply(int[][] a, int[][] b) {
            int[][] c = new int[2][2];
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
                }
            }
            return c;
        }
    }

}
