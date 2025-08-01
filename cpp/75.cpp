#include "header.h"

// bubble sort
// time: O(n^2)
// space: O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        for(int i = 0; i < len; i++){
            for(int j = 0; j < len-i-1; j++){
                if(nums[j] > nums[j+1]) 
                    swap(nums[j], nums[j+1]);
            }
        }
        
    }
};

/**
 * swap all zeros to the beginning of the array. 
 * Then swap all ones next to zeros 
 * time: O(n)
 * space: O(1)
 */
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int ptr = 0;
        int len = nums.size();

        // swap all zeros to the beginning
        for(int i = 0; i < len; i++) {
            if(nums[i] == 0) {
                swap(nums[i], nums[ptr]);
                ptr ++;
            }
        }

        // swap all ones next to zeros
        for(int i = 0; i < len; i++) {
            if(nums[i] == 1) {
                swap(nums[i], nums[ptr]);
                ptr ++;
            }
        }
        
    }
};

/**
 * use 2 pointers. 
 * swap all zeros to the beginning of the array. 
 * Then swap all ones next to zeros 
 * time: O(n)
 * space: O(1)
 * 
 */

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p_0 = 0;
        int len = nums.size();
        int p_1 = 0;
        // swap all zeros to the beginning
        for(int i = 0; i < len; i++) {
            if(nums[i] == 1) {
                swap(nums[i], nums[p_1]);
                p_1++;
            } else if(nums[i] == 0) {
                swap(nums[i], nums[p_1]);
                swap(nums[p_0], nums[p_1]);
                p_1++;
                p_0++;
            }

        }
    }
};


/**
 * use 2 pointers. 
 * swap all zeros to the beginning of the array
 * and swap all twos to the end of the array
 */
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p_0 = 0;
        int len = nums.size();
        int p_2 = len-1;
        // swap all zeros to the beginning
        for(int i = 0; i <= p_2; i++) {
            while(i <= p_2 && nums[i] == 2){
                swap(nums[i], nums[p_2]);
                p_2--;    
            }
            if(nums[i]==0){
                swap(nums[i], nums[p_0]);
                p_0++;
            }

        }
    }
};