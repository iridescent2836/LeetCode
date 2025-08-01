#include "header.h"

class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        int temp = 0;
        for(char ch : s){
            if(ch == ' '){
                count = temp == 0 ? count : temp;
                temp = 0;
            } else {
                temp++;
            }
        }
        // deal with the situation that the last word
        // is actually at the end of the string. 
        count = temp == 0 ? count : temp; 
        return count;
    }
};