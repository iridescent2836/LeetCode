#include "header.h"


// dp[i]: s[0:i] satisfied
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        auto wordDictSet = unordered_set<string>();
        for(auto word: wordDict) {
            wordDictSet.insert(word);
        }
        int len = s.size();
        vector<bool>dp(len+1);
        dp[0] = true;

        for(int i = 1; i <= len; i++){
            for(int j = 0; j < i; j++){
                if(dp[j] && wordDictSet.find(s.substr(j,i-j))!=wordDictSet.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[len];
    }
};