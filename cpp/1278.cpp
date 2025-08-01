#include "header.h"

// dp
// dp[i][r] the minimum change that s[0...r] is cut i times
// and is devided into i+1 substrings
// dp[i][r] = min(l = i...r)dp[i-1][l-1]: l >= i: because is string is cut i-1 times, it has to have no less than i characters

//            + minChange(l,r) -> that minimum changes that make s[l...r] a palindrome


class Solution {
public:
    int palindromePartition(string s, int k) {
        int len = s.size();
        vector<vector<int>> minChange(len, vector<int>(len,0));
        for(int l = len-1; l >= 0; l--){
            for(int r= l+1; r < len; r++){
                minChange[l][r] = minChange[l+1][r-1] + (s[l] != s[r]);
            }
        }


        vector<vector<int>> dp(k, vector<int>(len,len+1));

        dp[0] = move(minChange[0]);

        for(int i = 1; i < k; i++){
            // for(int r = i; r < len; r++){
            // an optimization
            for(int r = i; r <= len-k+i; r++){ // to make sure s[r+1...len-1] can be cut k-1-i times
                for(int l = i; l <= r; l++){
                    dp[i][r] = min(dp[i][r], dp[i-1][l-1]+minChange[l][r]);
                }
            }
        }
        return dp[k-1][len-1];
    }
};