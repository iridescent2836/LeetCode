#include "header.h"

// truth table
// | (ai bi) | xi  | 新的 (ai bi) |
// |---------|-----|--------------|
// | 00      | 0   | 00           | (0+0)%3=0
// | 00      | 1   | 01           | (0+1)%3=1
// | 01      | 0   | 01           | (1+0)%3=1
// | 01      | 1   | 10           | (1+1)%3=2
// | 10      | 0   | 10           | (2+0)%3=2
// | 10      | 1   | 00           | (2+1)%3=0


// least simplified
// ai = (~ai & bi & xi) | (ai & ~bi & ~xi)
// bi = (~ai & ~bi & xi) | (~ai & bi & ~xi) = ~a & (b ˆ x)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0;
        int b = 0;
        for(int x: nums){
            tie(a, b) = pair{(~a & b & x) | (a & ~b & ~x), ~a & (b ^ x)};
        }
        return b;
    }
};

// extremely simplified
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0;
        int b = 0;

        for(int x: nums){
            b = (b ^ x) & ~a;
            a = (a ^ x) & ~b;
        }
        return b;
    }
};