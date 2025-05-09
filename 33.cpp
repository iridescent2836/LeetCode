#include "header.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        int l = 0;
        int r = len-1;

        while(l <= r){
            int mid = (l + r + 1) >> 1;
            if(nums[mid] == target) return mid;
            // nums[0,...,mid] 有序
            if(nums[0] < nums[mid]){
                if(nums[0] <= target && target < nums[mid]){
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if(nums[mid] < target && target <= nums[len-1]){
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }

            }
        }
        return -1;
    }
};