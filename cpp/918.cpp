#include "header.h"

/**
 * max could come from: 
 * nums[i,...,j]
 * or
 * nums[0,...,i] + nums[j,...,len-1]
 * 
 */
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int len = nums.size();
        
        vector<int> leftMax(len);
        leftMax[0] = nums[0];
        int pre = nums[0];
        int ret = nums[0];
        int leftSum = nums[0];
        for(int i = 1; i < len; i++){
            pre = max(pre + nums[i], nums[i]);
            ret = max(pre, ret);
            leftSum += nums[i];

            // leftMax[i] is the max sum of subarray of nums[0,...,i] and start with nums[0]
            leftMax[i] = max(leftMax[i-1], leftSum);
        }

        int rightSum = 0;
        for(int i = len-1; i>0;i--){
            rightSum += nums[i];
            ret = max(ret, rightSum + leftMax[i-1]);
        }

        return ret;
    }
};

/**
 * max of nums[0,...,i] + nums[j,...,len-1] 
 * equals to get the min of nums[i+1,...,j-1]
 */

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int len = nums.size();
        
        vector<int> leftMax(len);
        leftMax[0] = nums[0];
        int preMax = nums[0];
        int preMin = nums[0];
        int maxRet = nums[0];
        int minRet = nums[0];
        int sum = nums[0];
        for(int i = 1; i < len; i++){
            preMax = max(nums[i], preMax + nums[i]);
            maxRet = max(maxRet, preMax);

            preMin = min(nums[i], preMin+ nums[i]);
            minRet = min(minRet, preMin);
            sum += nums[i];

        }

        if(maxRet < 0) return maxRet; // mean the whole array is negative. Hence maxRet is the best already. maxRet here equals to max(nums[:-1])
        else return max(maxRet, sum - minRet);

    }
};

// 作者：力扣官方题解
// 链接：https://leetcode.cn/problems/maximum-sum-circular-subarray/solutions/2350660/huan-xing-zi-shu-zu-de-zui-da-he-by-leet-elou/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        deque<pair<int, int>> q;
        int pre = nums[0], res = nums[0];
        q.push_back({0, pre});
        for (int i = 1; i < 2 * n; i++) {
            while (!q.empty() && q.front().first < i - n) {
                q.pop_front();
            }
            pre += nums[i % n];
            res = max(res, pre - q.front().second);
            while (!q.empty() && q.back().second >= pre) {
                q.pop_back();
            }
            q.push_back({i, pre});
        }
        return res;
    }
};

