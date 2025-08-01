#include "header.h"

// time: O(n)
// space: O(n)
// dp[n] = dp[n-1] + dp[n-2]
// dp[0] = 1, dp[1] = 1
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, 1);
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

// time: O(n)
// space: O(1)
class Solution {
public:
    int climbStairs(int n) {
        if(n == 0 || n == 1) return 1;
        
        int former = 1;
        int formerer = 1;
        int ret = 0;
        for(int i = 2; i <= n; i++){
            ret = former + formerer;
            formerer = former;
            former = ret;
        }
        return ret;
    }
};

// time: O(1)
// space: O(1)
class Solution {
public:
    long long fib(int n) {
        const double sqrt5 = sqrt(5);
        const double phi = (1 + sqrt5) / 2;
        return round(pow(phi, n) / sqrt5);
    }
    int climbStairs(int n) {
        return fib(n+1);
    }
};

