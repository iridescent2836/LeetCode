#include "header.h"

// brute way
class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
       int len = prices.size();
       int max = INT32_MIN;
       for(int i = 0; i < len; i++){
            for(int j = i+1; j < len; j++){
                if(prices[j] - prices[i] > max) max = prices[j] - prices[i];
            }
       }
       return max>0?max:0;
    }
};


// dp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len <= 1) return 0;
        int minPrice = prices[0];
        int maxProfit = INT32_MIN;
        for(int i = 1; i < len; i++){
            if(prices[i] - minPrice > maxProfit) maxProfit = prices[i] - minPrice;
            if(prices[i] < minPrice) minPrice = prices[i];
        }
        return maxProfit > 0 ? maxProfit : 0;
    }
};

// dp optimized
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len <= 1) return 0;
        int minPrice = prices[0];
        int maxProfit = 0;
        for(int i = 1; i < len; i++){
            int diff = prices[i] - minPrice;
            if(diff < 0){
                minPrice = prices[i];
                continue;
            }
            if(diff > maxProfit) maxProfit = diff;
        }
        return maxProfit;
    }
};



int main(){
    Solution s;
    vector<int> prices = {7,1,5,3,6,4};
    cout << s.maxProfit(prices) << endl;
    return 0;
}