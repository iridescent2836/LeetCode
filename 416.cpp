#include "header.h"


/**
 * target = (sum(nums))/2
 * 开始可以根据一系列判断剪枝
 * dp[i][j]: 是否可以从nums[0,...,i]中选取一组数字使得其和为j
 * dp[n-1][target]即为所求
 * dp[i][0] = true for all i
 * dp[0][nums[0]] = true
 * 
 * 
 * 如果 j≥nums[i]，则对于当前的数字 nums[i]，可以选取也可以不选取，两种情况只要有一个为 true，就有 dp[i][j]=true。
 *      如果不选取 nums[i]，则 dp[i][j]=dp[i−1][j]；
 *      如果选取 nums[i]，则 dp[i][j]=dp[i−1][j−nums[i]]。
 * 如果 j<nums[i]，则在选取的数字的和等于 j 的情况下无法选取当前的数字 nums[i]，因此有 dp[i][j]=dp[i−1][j]。
 * 
 */
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int len = nums.size();
        if(len < 2) return false;
        int maxNum = 0;
        int sum = 0;
        for(int num: nums){
            sum += num;
            maxNum = max(num, maxNum);
        }
        if((sum & 1) != 0) return false;

        int target = sum >> 1;
        if(maxNum > target) return false;

        vector<vector<bool>> dp(len, vector<bool>(target+1, false));
        for (int i = 0; i < len; i++) {
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;
        for (int i = 1; i < len; i++) {
            int num = nums[i];
            for (int j = 1; j <= target; j++) {
                if (j >= num) {
                    // dp[i-1][j] 不选择nums[j]
                    // dp[i-1][j-num] 选择nums[j]
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - num];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[len - 1][target];

    }
};