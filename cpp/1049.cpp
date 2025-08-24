#include "header.h"

/**
 * dp[i][j]: 在前 i 个石头里选，如果能使重量为 j ，则为 true， 否则为 false
 * 
 * 将石头分为两堆，使得两方的重量尽可能接近总重量的一半
 */
class Solution {
public:
    int lastStoneWeightII(vector<int> &stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int n = stones.size(), m = sum / 2;
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (j < stones[i]) {
                    dp[i+1][j] = dp[i][j];
                } else {
                    dp[i+1][j] = dp[i][j] || dp[i][j-stones[i]];
                }
            }
        }

        for(int j = m; ;--j) {
            if (dp[n][j]) return sum - j * 2;
        }
    }
};

