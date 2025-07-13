#include "header.h"


// dynamic programming
class Solution1 {
public:
    int jump(vector<int>& nums) {

        int len = nums.size();
        vector<int> dp(nums.size(), len + 1);

        dp[0] = 0;
        for(int i = 0; i < len; i++) {
            for(int j = 1; j <= nums[i]; j++) {
                if(i + j < len) {
                    // dp[i+j]: 从i起跳能跳到的所有位置
                    dp[i + j] = min(dp[i + j], dp[i] + 1);
                }
            }
        }

        return dp[len - 1];
    }
};



// greedy
/*
Maintain a 'boundary,' and at each step,
choose the next starting point that will
expand the 'boundary' the most.
*/
class Solution2 {
public:
    int jump(vector<int>& nums) {
        int boundary = 0;
        int maxPos = 0;
        int step = 0;
        int startJumpPos = 0;
        int len = nums.size();
        

        while(boundary < len - 1) {
            
            for(int i = startJumpPos; i <= boundary; i++) {
                // can reach a further position
                // update max position and start jump position
                if(maxPos < i + nums[i]) {
                    maxPos = i + nums[i];
                    startJumpPos = i;
                } 
            }
            // update boundary: the furtherest position that 
            // can be reached from the start position
            boundary = maxPos;
            step++;
        }

        return step;
    }
};