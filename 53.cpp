#include "header.h"

// brute force
class Solution000 {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if(len == 0){
            cerr << "You entered an empty array" << endl;
            exit(1);
        }
        int maxSum = INT32_MIN;
        for(int start = 0; start < len;start++){
            int temp = 0;
            for(int end = start;end < len; end++){
                temp+= nums[end];
                if(temp > maxSum) maxSum = temp;
            }
        }
        return maxSum;
    }
};
    

/**
 * for all i <= j, `n` is the length of array `a`
 * a[i]+...+a[j] == (a[0]+...+a[j]) - (a[0]+...+a[i])
 * so we only need to calculate the sum of prefix at the beginning,
 * and then we can accelerate the calculation significantly
 * 
 * prefix[i] = a[0]+...+a[i];
 * a[i]+...+a[j] = prefix[j] - prefix[i-1], for any i > 0;
 * 
 * time: O(n^2)
 */


class Solution001 {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if(len == 0){
            cerr << "You entered an empty array" << endl;
            exit(1);
        }
        if(len == 1) return nums[0];

        int maxSum = INT32_MIN;
        vector<int> prefix(len,0);
        int sumTemp = 0;
        for(int i = 0; i < len; i++){
            sumTemp += nums[i];
            prefix[i] = sumTemp;
            if(sumTemp > maxSum) maxSum = sumTemp;
        }

        for(int begin = 1; begin < len; begin++){
            for(int end = begin; end < len; end++){
                int temp = prefix[end] - prefix[begin-1];
                if(temp > maxSum) maxSum = temp;
            }
        }
        return maxSum;
    }
};

/**
 * dp
 * dp[i] means the max sum of contiguous subarry that ends with nums[i]
 * dp[i] = max(dp[i-1]+nums[i], nums[i])
 * 
 * as dp[i] is only related with dp[i-1], we use a single
 * variable pre to store pre
 * 
 * time: O(n)
 * space: O(1)
 */
class Solution002 {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if(len == 0){
            cerr << "You entered an empty array" << endl;
            exit(1);
        }
        if(len == 1) return nums[0];

        int pre = nums[0];
        int maxSum = pre;
        for(int i = 1; i < len; i++){
            pre = max(pre+nums[i], nums[i]);
            maxSum = max(pre,maxSum);
        }
        return maxSum;
    }
};

/**
 * devide and conquer
 * 
 * for detailed version of explanation, please refer to leetcode official solution:
 * https://leetcode.cn/problems/maximum-subarray/solutions/228009/zui-da-zi-xu-he-by-leetcode-solution/?envType=study-plan-v2&envId=top-interview-150
 * it's the basic of "线段树"
 */
class Solution003 {
public:
    struct Status
    {
        int lSum, rSum, mSum, iSum;
    };
    Status pushUp(Status l, Status r) {
        int iSum = l.iSum + r.iSum;
        int lSum = max(l.lSum, l.iSum + r.lSum);
        int rSum = max(r.rSum, r.iSum+l.rSum);
        int mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum);
        return (Status) {lSum, rSum, mSum, iSum};
    }

    Status get(vector<int>& a, int l, int r){
        if(l == r) {
            return (Status) {a[l], a[l], a[l], a[l]};
        }
        int m = (l + r) >> 1;
        Status lSub = get(a,l,m);
        Status rSub = get(a,m+1,r);
        return pushUp(lSub, rSub);
    }
    int maxSubArray(vector<int>& nums) {
        return get(nums,0,nums.size() - 1).mSum;
    }
};