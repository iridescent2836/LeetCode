#include "header.h"

// very clever method. 
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0)) return false;
        if(0 <= x && x <= 9) return true;

        int revertedNumber = 0;
        while(x > revertedNumber){
            revertedNumber = revertedNumber*10+x%10;
            x/=10;
        }
        return x == revertedNumber || x == revertedNumber / 10;
    }
};