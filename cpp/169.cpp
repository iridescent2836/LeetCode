#include "header.h"
#include <unordered_map>

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        int frequency = len/2;
        unordered_map<int,int> m;
        int majority;

        for(int i = 0; i < len; i++){
            m[nums[i]]++;
            if(m[nums[i]] > frequency) return nums[i];
        }
    }
};

// 赌狗算法
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        int frequency = len/2;
        while (true) {
            int candidate = nums[rand() % len];
            int count = 0;
            for (int num : nums){
                if (num == candidate)
                    ++count;
                if (count > frequency)
                    return candidate;
            }
        }
        return -1;
    }
};
    
// Boyer-Moore 投票算法
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        int candidate = -1;
        int count = 0;
        for(int num: nums){
            if(num == candidate) ++count;
            else if(--count < 0){
                candidate = num;
                count = 1;
            }
        }
        return candidate;
    }
};
