#include "header.h"


// find the common prefix
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
        while(left < right){
            left >>=1;
            right >>=1;
            shift++;
        }
        return left << shift;
    }
};

// Brian Kernighan's algorithm: to remove the rightmost 1 in `n`,
//  just calculate n = n & (n - 1)
// e.g. n == 1100, n-1 == 1011, n & (n-1) == 1000, the rightmost 1 is removed from 1100. 
// we use this algorithm to find the common prefix
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while(left < right){
            right = right & (right - 1); // remove the rightmost 1
        }
        return right;
    }
};