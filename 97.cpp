#include "header.h"

/**
 * dp[i][j] = true: means s1[0,...,i-1] and s2[0,...,j-1] can form s3[0,...,i+j-1]
 * space: O(l1*l2)
 * time: O(l1*l2)
 */
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.size();
        int l2 = s2.size();
        int l3 = s3.size();

        if(l3 != l1 + l2) return false;

        vector<vector<bool>> dp(l1+1,vector<bool>(l2+1,false));
        dp[0][0] = true;
        for(int i = 0; i <= l1; i++){
            for(int j = 0; j <= l2; j++){
                int idx = i + j - 1;
                if(i > 0)
                    dp[i][j] = dp[i][j] | (dp[i-1][j] && s1[i-1] == s3[idx]);
                if(j > 0)
                    dp[i][j] = dp[i][j] | (dp[i][j-1] && s2[j-1] == s3[idx]);
            }
        }
        return dp[l1][l2];
    }
};


/**
 * an optimized version
 * 
 * for iteration `i`
 * dp[j] = true: means s1[0,...,i-1] and s2[0,...,j-1] can form s3[0,...,i+j-1]
 * space: O(l2)
 * time: O(l1*l2)
 */


class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.size();
        int l2 = s2.size();
        int l3 = s3.size();

        if(l3 != l1 + l2) return false;

        vector<bool> dp(l2+1,false);
        dp[0] = true;
        for(int i = 0; i <= l1; i++){
            for(int j = 0; j <= l2; j++){
                int idx = i + j - 1;
                if(i > 0)
                    dp[j] = (dp[j] && s1[i-1] == s3[idx]);
                if(j > 0)
                    dp[j] = dp[j] | (dp[j-1] && s2[j-1] == s3[idx]);
            }
        }
        return dp[l2];
    }
};