#include "header.h"

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int lenS = s.size();
        int idxS = 0;
        for(auto ch: t){
            if(idxS == lenS) break;
            if(s[idxS] == ch) idxS++;
        }
        return idxS == lenS;
    }
};

// dp
/**
 * dp[i][j]: `i` is the idx in string `t`; `j` represents characters from `a` to `z`
 * dp[i][j] means the first appearence of character `j` at or after the position `i` in string `t`
 * 
 * if(t[i] == j) dp[i][j] = i
 * else dp[i][j] = dp[i+1][j]
 * 
 * if there are `k` string `s` that need to be checked, the time complexity is O(len(t) + k*len(s))
 * if `k` is large enough, the time complexity is O(k*len(s)), while the above algorighm is O(k*(len(s) + len(t)))
 * 
 */
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int lenT = t.size();
        int lenS = s.size();

        vector<vector<int>> dp(lenT+1,vector<int>(26,-1));
        
        for(int i = 0; i < 26; i++) {
            dp[lenT][i] = -1;
        }
        for(int i = lenT-1; i >= 0; i--) {
            for(int j = 0; j < 26; j++) {
                if(t[i] == 'a' + j) dp[i][j] = i;
                else dp[i][j] = dp[i+1][j];

            }
        }
        int curr = 0;
        for(int i = 0; i < lenS; i++) {
            // `dp[curr][s[i] - 'a']`: the first appearance of `char s[i]` in `string t` at or after `curr` position. 
            if(dp[curr][s[i] - 'a'] == -1) {
                return false;
            }
            curr = dp[curr][s[i]-'a'] + 1;
        }
        return true;
    }
};
    
