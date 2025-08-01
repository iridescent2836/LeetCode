#include "header.h"

/**
 * dp[i][j]: the maximum length substring of text1[0,...,i-1] and text2[0, ..., j-1]
 * we make sure text1 is shorter than or equal to text2
 * if text1[i-1] == text2[j-1]
 *     dp[i][j] = dp[i-1][j-1] + 1 
 * else
 *     dp[i][j] = max(dp[i-1][j], dp[i][j-1])
 */
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if(text1.size() > text2.size()) swap(text1, text2);

        int len1 = text1.size();
        int len2 = text2.size();

        vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));
        for(int i = 1; i <= len1; i++){
            char ch1 = text1[i-1];
            for(int j = 1; j <= len2; j++){
                char ch2 = text2[j-1];
                if(ch1 == ch2) dp[i][j] = dp[i-1][j-1] +1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[len1][len2];
    }
};