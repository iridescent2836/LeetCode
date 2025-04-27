#include "header.h"

//The algorithm is designed under the assumption that the array nums contains ​​unique elements​​
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while(left < right){
            int mid = (left+right) >> 1;
            // mid 到 mid+1 是下坡，那么 mid 有可能是山峰，所以 right=mid，mid 不能离开查找区间
            if(nums[mid] > nums[mid+1]){
                right = mid;
            }
            // mid 到 mid+1 是上坡，那么 mid 不可能是山峰，所以 left=mid+1，mid 可以离开查找区间
            else{ // nums[mid] < nums[mid+1]
                left = mid+1;
            }
        }
        return left;
    }
};