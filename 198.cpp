#include "header.h"


// dp[i] = max(nums[i] + dp[i-k]) 2 <= k <= i
// dp[i] is the maximum money you can get if you steal house[i]
// time: O(n^2)
// space: O(n)
class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) return nums[0];

        vector<int> dp(size, 0);
        dp[0] = nums[0];
        dp[1] = nums[1];
        int Max = max(nums[0], nums[1]);
        for(int i = 2; i < size; i++){
            int Max__ = nums[i] + dp[i-2];
            for(int k = 3; k <= i; k++){
                Max__ = max(Max__, nums[i] + dp[i-k]);
            }
            dp[i] = Max__;
            Max = max(Max, Max__);
        }
        return Max;
    }
};

// dp[i] = max(dp[i-2] + nums[i], dp[i-1])
// dp[i-2] + nums[i]: you steal house[i]
// dp[i-1]: you don't steal house[i]
// dp[i] is the maximum money you can get if you steal to house[i]
// time: O(n)
// space: O(n)
class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) return nums[0];

        vector<int> dp(size, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < size; i++){
            dp[i] = max(dp[i-1], nums[i]+dp[i-2]);
        }
        return dp[size-1];
    }
};

// an optimized version
// time: O(n)
// space: O(1)+
class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) return nums[0];

        int first = nums[0];
        int second = max(nums[0], nums[1]);
        int temp;
        for(int i = 2; i < size; i++){
            temp = second;
            second = max(first + nums[i], second);
            first = temp;
        }
        return second;
    }
};