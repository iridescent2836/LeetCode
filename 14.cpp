#include "header.h"

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int numStrs = strs.size();
        if(numStrs == 1) return strs[0];

        int minLen = INT32_MAX;
        for(int i = 0; i < numStrs; i++){
            int len = strs[i].size();
            if(len < minLen) minLen = len;
        }
        string ans;
        for(int i = 0; i < minLen; i++) {
            char ch = strs[0][i];
            bool isPrefix = true;
            for(int j = 1; j < numStrs; j++){
                if(strs[j][i] != ch) {
                    isPrefix = false;
                    break;
                }
            }
            if(isPrefix) ans.push_back(ch);
            else break;
        }
        return ans;
    }
};