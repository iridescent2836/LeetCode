#include "header.h"


// similar to 27, use 2 pointers
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1) {
            return len;
        }

        int ready = 1;
        for(int i = 1; i < len; i++) {
            if(nums[i] != nums[ready - 1]) {
                nums[ready] = nums[i];
                ready++;
            }
        }

        return ready;

    }
};