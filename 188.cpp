#include "header.h"


/**
 * pretty similiar to 123.cpp
 * time: O(k*time)
 * space: O(k) 
 */
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int size = prices.size();
        if(size <= 1) return 0;

        vector<int> buy(k, -prices[0]);
        vector<int> sell(k, 0);
        int buy1 = -prices[0];
        int sell1 = 0;
        int buy2 = -prices[0]; // actually an illegal state, but initialize it for future processing
        int sell2 = 0;
        for(int i = 1; i < size; i++){
            for(int j = 0; j < k; j++){
                if(j == 0) 
                    buy[j] = max(buy[j], -prices[i]);
                 else
                    buy[j] = max(buy[j], sell[j-1] - prices[i]);
                
                sell[j] = max(sell[j], buy[j] + prices[i]);
            }
        }
        return sell[k-1];
    }
};