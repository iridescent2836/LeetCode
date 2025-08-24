# include "header.h"

/**
 * side window
 * make sure there is at most 1 zero in the window
 */
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int size = nums.size();
        int begin = 0;
        int end = 0;
        int length = 0;
        int zero_cnt = 0;
        int ret = 0;
        for (; end < size; ++end) {
            if (nums[end] == 1) {
                ++length;
            } else {
                ++zero_cnt;
                if (zero_cnt == 2) {
                    // move begin, to skip a zero
                    while ( nums[begin] != 0) ++begin;
                    ++ begin;
                    --zero_cnt;
                    length = end - begin;
                } 
            }
            if(zero_cnt == 0) ret = max(ret, length - 1); // you have to delete a number
            else ret = max(ret, length);
        }
        return ret;
    }
};