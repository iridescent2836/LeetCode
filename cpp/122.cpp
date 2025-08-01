#include "header.h"

// greedy, try to gain all profits
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int ans = 0;
        for(int i = 0; i < len-1; i++){
            int temp = prices[i+1] - prices[i];
            ans += temp > 0 ? temp : 0;
        }
        return ans;
    }
};

// dp
/*
dp[0][i]: at the i-th day, don't hold any stock, the current maximum accumulated profit
dp[1][i]: at the i-th day, hold one stock, the current maximum accumulated profit

dp[0][i] = max(dp[0][i-1], dp[1][i-1] + prices[i]);
: if last day also don't hold any stock, then today's profit is the same as yesterday.
otherwise, the profit will be increased because of selling a stock today

dp[1][i] = max(dp[1][i-1], dp[0][i-1] - prices[i]);
: if last day also hold a stock, then today's profit is the same as yesterday.
otherwise, the profit will be decreased because of buying a stock today

*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<vector<int>> dp(2, vector<int>(len,0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for(int i = 1; i < len; i++){
            dp[0][i] = max(dp[0][i-1], dp[1][i-1] + prices[i]);
            dp[1][i] = max(dp[1][i-1], dp[0][i-1] - prices[i]);
        }

        if(dp[0][len-1] < 0 && dp[1][len-1] < 0) return 0;
        return dp[0][len-1] < dp[1][len-1] ? dp[0][len-1] : dp[1][len-1];
    }
};
