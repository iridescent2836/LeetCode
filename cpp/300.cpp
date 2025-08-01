#include "header.h"

/**
 * dp[i] = the max length of sub consequence that include i
 * dp[i] = max(dp[i-k]+1), 1 <= k <= i && nums[i-k] < nums[i]
 * time: O(n^2)
 * space: O(n)
 */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        if(size <= 1) return size;
        vector<int> dp(size, 1);
        int ret = 1;
        for(int i = 1; i < size; i++){
            for(int k = 1; k <=i; k++){
                if(nums[i-k] < nums[i]){
                    dp[i] = max(dp[i], dp[i-k]+1);
                }
            }
            ret = max(dp[i], ret);
        }
        return ret;
    }
};

/**
 * greedy + binary search
 * very very clever method
 * time: O(nlogn)
 * space: O(n)
 */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // 'q' will store the smallest possible tail of all increasing subsequences
        // with different lengths. It is not the actual subsequence.
        // e.g. q[i] 存储的是长度为i+1的递增子序列的最小的tail值
        std::vector<int> q;

        for (int i = 0; i < nums.size(); ++i) {
            // If 'q' is empty or current number is greater than the last in 'q',
            // it can extend the current longest increasing subsequence.
            if (q.empty() || q.back() < nums[i]) {
                q.push_back(nums[i]);
            } 
            else {
                // Use binary search to find the first element in 'q' that is
                // greater than or equal to nums[i] and replace it.
                // This maintains a smaller potential tail value.
                int l = 0, r = q.size() - 1;
                while (l < r) {
                    int mid = (l + r) >> 1;
                    if (nums[i] <= q[mid])
                        r = mid;
                    else
                        l = mid + 1;
                }
                q[r] = nums[i];  // Replace the found element with nums[i]
            }
        }

        // The length of 'q' is the length of the longest increasing subsequence.
        return q.size();
    }
};
    