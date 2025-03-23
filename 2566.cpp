#include "header.h"

class Solution {
public:
    int minMaxDifference(int num) {
        if(num <= 9) return 9;

        int copyNum = num;
        int biggerNum = -1;
        int smallerNum = -1;
        while(copyNum > 0){
            int temp = copyNum%10;
            // change ghe highest digit to 0 to make the number smallest
            smallerNum = temp; 
            // change the highest non-9 digit to 9 to make the number biggest
            if(copyNum != 9) biggerNum = temp; 
            copyNum /= 10;
        }
        
    }
};