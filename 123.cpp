#include "header.h"

/**
 * stupid and not workable method
 * counter-example:
 * [1,2,4,2,5,7,2,4,9,0]
 * my result: (7-2) + (9-2) = 12
 * correct result: (7-1) + (9-2) = 13
 * 
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len == 0) return -1;
        if(len == 1) return 0;
        if(len == 2) return prices[1] - prices[0] > 0 ? prices[1] - prices[0] : 0;

        vector<int> profits;
        int profit = 0;
        for(int i = 1; i < len; i++){
            if(prices[i]-prices[i-1] >= 0){
                profit += prices[i] - prices[i-1];
            } else {
                profits.push_back(profit);
                profit = 0;
            }
        }
        if(profit > 0) profits.push_back(profit);
        

        sort(profits.begin(), profits.end());
        len = profits.size();
        if(len >= 2){
            return profits[len-1]+profits[len-2];
        } else if(len == 1){
            return profits[0];
        } else {
            return 0;
        }
    }
};

/**
 * Since we can complete at most two transactions, at the end of any given day, we will be in one of the following five states:
 * 
 * 1. No operations have been performed;
 * 2. Only one buy operation has been performed;
 * 3. One buy operation and one sell operation have been performed
 * 4. A second buy operation has been performed after completing the first transaction;
 * 5. Both transactions have been completed.
 * 
 * Since the profit of the first state is obviously 0, 
 * we do not need to record it. For the remaining four states, 
 * we denote their maximum profits as buy₁, sell₁, buy₂, and sell₂, respectively.
 * 
 * if it's the `i` th day, we add ' to refer 
 * to the state of `i-1` th day. 
 * buy1 = max(buy1', -prises[i]) : unchange or buy at day i
 * sell1 = max(sell1', buy1 + prices[i]) : unchange or sell at day i
 * buy2 = max(buy2', sell1 - prices[i])
 * sell2 = max(sell2', buy2 + prices[i])
 * 
 * time: O(n)
 * space: O(1)
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if(size <= 1) return 0;
        int buy1 = -prices[0];
        int sell1 = 0;
        int buy2 = -prices[0]; // actually an illegal state, but initialize it for future processing
        int sell2 = 0;
        for(int i = 1; i < size; i++){
            buy1 = max(buy1, -prices[i]);
            sell1 = max(sell1, buy1 + prices[i]);
            buy2 = max(buy2, sell1 - prices[i]);
            sell2 = max(sell2, buy2 + prices[i]);
        }
        return sell2;
    }
};