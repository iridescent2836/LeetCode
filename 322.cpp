#include "header.h"

// bfs
// count[i]: the minimum number of coins used to achieve amount `i+1`
class Solution {
public:
    vector<int> count;
    int dp(const vector<int>& coins, int remain){
        if(remain < 0) return -1;
        if(remain == 0) return 0;
        if(count[remain-1] != 0) return count[remain-1];
        int Min = INT32_MAX;
        for(int coin: coins){
            int res = dp(coins, remain-coin);
            if(res >= 0 && res < Min)
                Min = res + 1;
            
        }
        count[remain-1] = Min == INT32_MAX ? -1 : Min;
        return count[remain - 1];
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount <= 0) return 0;
        count.resize(amount);
        return dp(coins, amount);
    }
};

// dp
// dp[i]: the minimum number of coins used to achieve amount `i` 
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,amount+1);
        dp[0] = 0;
        int numCoins = coins.size();

        for(int i = 1; i <= amount; i++){
            for(int j = 0; j < numCoins; j++){
                if(coins[j] <= i){
                    dp[i] = min(dp[i], dp[i-coins[j]]+1);
                }
            }
        }
        

        return dp[amount] > amount ? -1 : dp[amount];
    }
};

// optimization for dp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount+1,INT_MAX/2);
        memo[0]=0;
        for(int x:coins)
        {
            for(int j=x;j<=amount;j++)
            {
                memo[j]=min(memo[j],memo[j-x]+1);
            }
        }
        return memo[amount]<INT_MAX/2?memo[amount]:-1;
    }
};