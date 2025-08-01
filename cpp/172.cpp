#include "header.h"


class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        for (int i = 5; i <= n; i += 5) {
            for (int x = i; x % 5 == 0; x /= 5) {
                ++ans;
            }
        }
        return ans;
    }
};
/**
 * trailingZeroes(int N)
 * 本质是求 1, 2, 3, ... , N 中， 各数字中质因子5的个数
 * https://leetcode.cn/problems/factorial-trailing-zeroes/solutions/47030/xiang-xi-tong-su-de-si-lu-fen-xi-by-windliang-3/?envType=study-plan-v2&envId=top-interview-150
 * 很通俗易懂的数学说明。 
 */
class Solution {
public:
    int trailingZeroes(int n) {
        int ret = 0;
        while(n > 0){
            n /= 5;
            ret += n;
        }
        return ret;
    }
};