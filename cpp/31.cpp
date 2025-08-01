#include "header.h"

/**
 * 暴力解法，递归加排序。
 * time: O(n!)
 * space: O(n)
 * 
 * 真是有够暴力的。
 * 也是会做屎的，这么屎的代码山都写出来了。
 */
typedef long long ll;
class Solution {
private:
    ll curr;
    ll result;
    ll min;
public:
    ll vecToNum(const vector<int>& nums){
        ll curr = 0;
        for(int num: nums){
            if(num >= 10 || num < 0) return -1;
            curr *= 10;
            curr += num;
        }
        return curr;
    }

    void intToVec(int target, vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            nums[i] = target % 10;
            target /= 10;
        }
        reverse(nums.begin(), nums.end());
    }

    void helper(int start, vector<int>& nums) {
        if(start == nums.size() - 1){
            ll num = vecToNum(nums);
            if(num < min) min = num;
            if(num > curr && num < result) result = num;
            return;
        }

        for(int i = start; i < nums.size(); i++) {
            swap(nums[i], nums[start]);
            helper(start+1, nums);
            swap(nums[i], nums[start]);
        }

    }

    void nextPermutation(vector<int>& nums) {
        curr = vecToNum(nums);
        min = result = INT64_MAX;
        
        helper(0, nums);
        if(result == INT64_MAX) intToVec(min, nums);
        else intToVec(result, nums);
    }
};

/**
 * 想法，如果满足nums[i] < nums[j] && i < j，则swap(nums[i], nums[j])就可以让nums字典序变大。
 * 要让其变成最接近原数组的更大值，则要尽可能使 i 更大， nums[j] 更小
 * num[j] 相同的情况下，j 越小越好
 *  e.g. 61533 -> 63513 < 63531
 * 
 * 可以证明
 */

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        int i = len - 2;
        // 找到第一个nums[i] < nums[i+1]
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if (i >= 0) {
            int j = len - 1;
            // 从右向左，找到第一个nums[j] 满足 nums[i] < nums[j]
            while (j >= 0 && nums[i] >= nums[j]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        // 可以证明nums[i+1, ..., n] 是严格升序的，可以讨论各种情况证明
        reverse(nums.begin() + i + 1, nums.end());
    }
};
