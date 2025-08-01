#include "header.h"

// using the fact that there is no duplicate element in nums
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        if(nums[left] < nums[right]) return nums[left];
        // go to the minimum
        int mid;
        int ans = 0;
        while(left < right) {
            mid = (left + right) >> 1;
            if(nums[mid] < nums[right]){
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return nums[left];
    }
};
/**
 * why this doesn't work
 * for the case like [4,5,6,7,0,1,2]
 * the first nums[mid] is `7`
 * and so the numd[left] will be `0`
 * then nums[mid] > nums[right] will always be satisfied. 
 * therefore, the answer is incorrect. 
 * 
 * in summary, the step 'left = mid + 1' is so risky that
 * make the nums[left] unreliable for checking the next movement
 * of `mid`
 */
class Solution_WRONG {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        if(nums[left] < nums[right]) return nums[left];
        // go to the minimum
        int mid;
        int ans = 0;
        while(left < right) {
            mid = (left + right) >> 1;
            if(nums[mid] > nums[left]){
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};