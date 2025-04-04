#include "header.h"

/**
 * Method bit by bit: 
 * time: O(logn)
 * space: O(1)
 * bad wirtting style
 */
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        uint32_t mask = 1;
        mask = mask & n;
        ans = ans | mask;
        for(int i = 0; i < 31; i++){
            ans <<= 1;
            n >>= 1;
            mask = 1;
            mask = mask & n;
            ans = ans | mask;
        }
        return ans;
    }
};



/**
 * Method bit by bit: 
 * time: O(logn)
 * space: O(1)
 * good wirtting style
 */

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ans = 0;
        for(int i = 0; i < 32; i++){
            ans |= (n & 1) << (31-i);
            n >>= 1;
        }
        return ans;
    }
};


/**
 * Method devide-and-conquer: 
 * 
 * too clever method
 * 
 *      abababab
 *  (&10101010, &01010101)
 *  a0a0a0a0 0b0b0b0b
 *  (>> 1, << 1)
 *  0a0a0a0a b0b0b0b0
 *  (|)
 *      babababa
 * time: O(1)
 * space: O(1)
 * 
 */

class Solution {
private:
const uint32_t M1 = 0x55555555; // 01010101010101010101010101010101
const uint32_t M2 = 0x33333333; // 00110011001100110011001100110011
const uint32_t M4 = 0x0f0f0f0f; // 00001111000011110000111100001111
const uint32_t M8 = 0x00ff00ff; // 00000000111111110000000011111111
public:
    uint32_t reverseBits(uint32_t n) {
        n = (n >> 1) & M1 | (n & M1) << 1;
        n = (n >> 2) & M2 | (n & M2) << 2;
        n = (n >> 4) & M4 | (n & M4) << 4;
        n = (n >> 8) & M8 | (n & M8) << 8;

    }
};