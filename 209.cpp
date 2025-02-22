#include "header.h"
class Solution1 {
public:

    // brute force
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = nums.size();
        // tranverse the length of substring
        for(int sublen = 1; sublen <= len; sublen++) {
            // the beginning of substring
            for(int i = 0; i <= len - sublen; i++) {
                int sum = 0;
                // sum
                for(int j = 0; j < sublen; j++) {
                    sum += nums[i + j];
                }
                if(sum >= target)
                    return sublen;
            }
        }
        return 0;
    }

};

class Solution2 {
public:
    // sliding window
    /*
    逻辑：
    如果存在一个最小长度子串可以使和大于等于target，那么通过增加end一定能将其包含进去
    再通过增加begin来减少长度就能找到。
    because if nums[u] + ... + nums[v] >= target, v >= u, v - u is min.
    there must have nums[0] + ... + nums[v] >= target.
    所以end++一定能包含这个子串，再通过begin++即能找到该子串
    */
    int minSubArrayLen(int target, vector<int>& nums) {
        int begin = 0, end = 0;
        int sum = 0;
        
        int minLen = nums.size() + 1;

        int len = nums.size();

        while(end < len) {
            sum += nums[end];
            // if sum greater than target,
            // shrink the length of substring
            // by adding begin
            while(sum >= target){
                minLen = min(minLen, end - begin + 1);
                sum -= nums[begin];
                begin++;
            }
            end++;
        }
        return minLen == len + 1 ? 0 : minLen;
    }
};

class Solution3 {
public:
    // 二分查找 + 前缀和
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = nums.size();
        if(len < 1) 
            return 0;
        
        int minLen = len + 1;
        // sum[i] = nums[0] + ... + nums[i - 1]
        // Use prefix sum to make the array sorted, facilitating binary search.
        vector<int> sums(len + 1, 0);
        for(int i = 1; i <= len; i++) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }

        // we need to find sums[bound] - sum[i] >= target
        // which equals sums[bound] >= target + sum[i]
        // and equals nums[i] + ... + nums[bound-1] >= target
        for(int i = 1; i <= len; i++) {
            int temp = target + sums[i];
            auto bound = lower_bound(sums.begin(), sums.end(), temp); // Binary Search
            if(bound != sums.end()){
                minLen = min(minLen, static_cast<int>((bound - sums.begin())) + 1 - i);
            }

        }

        return minLen == len + 1 ? 0 : minLen;
    }
};
