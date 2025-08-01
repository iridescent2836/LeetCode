#include "header.h"

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> ht;
        int len = nums.size();
        for(int i = 0; i < len; i++){
            if(ht.count(nums[i]) && i - ht[nums[i]] <= k){
                return true;
            }
            ht[nums[i]] = i;
        }
        return false;
    }
};