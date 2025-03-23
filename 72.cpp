#include "header.h"


// dp
// dp[i][j] means the min distance form word1[0,...,i-1] to word2[0,...,j-1]
// if(word1[i] == word1[j])
//  dp[i][j] = min(dp[i][j−1]+1,dp[i−1][j]+1,dp[i−1][j−1])
// ​else 
//  dp[i][j] = min(dp[i][j−1]+1,dp[i−1][j]+1,dp[i−1][j−1]+1) = 1 + min(dp[i][j−1],dp[i−1][j],dp[i−1][j−1])
 
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        if(len1 * len2 == 0) return len1+len2;
        vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));
        for(int i = 0; i <=len1; i++) dp[i][0] = i;
        for(int j = 0; j <= len2; j++) dp[0][j] = j;

        for(int i = 1; i <= len1; i++){
            for(int j = 1; j <= len2; j++){
                // notice, `i` and `j` represents the length of the substring
                // but not the index of the string. 
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = min(dp[i][j-1]+1,min(dp[i-1][j]+1,dp[i-1][j-1]));
                } else {
                    dp[i][j] = min(dp[i][j-1]+1,min(dp[i-1][j]+1,dp[i-1][j-1]+1));
                }
            }
        }
        return dp[len1][len2];
    }
};