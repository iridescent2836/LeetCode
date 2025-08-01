#include "header.h"

class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            int len = nums.size();
            if(len <= 2) {
                return len;
            }
            int ready = 2;
            for(int i = 2; i < len; i++){
                // nums[i] satisfy the requirement: 
                // no more than 2 duplicates
                if(nums[i] != nums[ready - 2]) {
                    nums[ready] = nums[i];
                    ready++;
                }
            }
            return ready;
        }
    };