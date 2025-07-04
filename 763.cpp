#include "header.h"

/**
 * greedy algorighm. 
 * well, hard to explain the reason, but the code is perfectly clear.
 * I now understand why linus would say "shut up and show me your code"
 * code are sometimes more clear than words. 
 */
class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> endPos;
        int len = s.size();
        for(int i = 0; i < len; i++){
            endPos[s[i]] = i;
        }

        int start = 0;
        int end = 0;
        vector<int> ans;
        for(int i = 0; i < len; i++){
            end = max(end, endPos[s[i]]);
            if(i == end){
                ans.push_back(end-start+1);
                start = end + 1;
            }
        }
        return ans;
    }
};