#include "header.h"

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // Traverse all elements in the array.
        int len = nums.size();
        int k = 0;
        vector<int> copyOfNums = nums;
        for(int i = 0; i < len; i++) {
            if(copyOfNums[i] != val) {
                nums[k] = copyOfNums[i];
                k++;
            }
        }
        return k;
    }
};