#include "header.h"


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        int len = nums.size();
        for(int i = 0; i < len; i++){
            ans = ans^nums[i];
        }
        return ans;
    }
};