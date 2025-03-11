#include "header.h"

class Solution {
public:
    bool checkPartitioning(string s) {
        int len = s.size();

        vector<vector<bool>> isPalindrome(len, vector<bool>(len,true));

        for(int l = len-1; l>=0; l--){
            for(int r = l+1; r< len; r++){
                isPalindrome[l][r] = isPalindrome[l+1][r-1] && (s[l] == s[r]);
            }
        }

        for(int r1 = 0; r1 < len-2;r1++){
            if(isPalindrome[0][r1]){
                for(int r2 = r1 + 1; r2 < len-1;r2++){
                    if(isPalindrome[r1+1][r2] && isPalindrome[r2+1][len-1]) return true;
                }
            }

        }
        return false;
    }
};