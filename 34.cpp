#include "header.h"

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        int left = 0;
        int right = len -1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] < target) left = mid + 1;
            else if( nums[mid] > target) right = mid - 1;
            else{
                left = mid;
                right = mid;
                while(left >= 0 && nums[left] == target) left--;
                while(right < len && nums[right] == target) right++;
                return {left+1, right-1};
            }
        }
        return {-1,-1};
    }
};

// rightidx = (the first idx that are > target) -1
// leftidx = the first idx that are >= target
// if rightidx >= leftidx, return [leftidx, rightidx]
// else, return [-1,-1]

class Solution {
public:
    // we use lower to better reuse this code, so that it can 
    // be both used to search the 1st idx that are > and >= target
    int binarySearch(vector<int>& nums, int target, bool lower){
        int left = 0; 
        int right = nums.size() - 1;
        int ans = nums.size(); // important, when nums.size() == 1, it will make this code function well
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] > target || (lower && nums[mid] >= target)){
                right = mid-1;
                ans = mid;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftIdx = binarySearch(nums,target,true);
        int rightIdx = binarySearch(nums, target, false) - 1;
        if(0 <= leftIdx && leftIdx <= rightIdx && rightIdx <= nums.size()-1){
            return vector<int>{leftIdx, rightIdx};
        }
        return vector<int>{-1,-1};
    }
};

